# Templates in C++

This Readme is dedicated to the Concept of **Templates**, the next content of it will go as follows:

* 1. **Why templates exist**
* 2. **Function templates**
* 3. **Class templates**
* 4. **Template compilation model**
* 5. **Non-type template parameters**
* 6. **Multiple/variadic-ish basics for C++98**
* 7. **Templates + inheritance**
* 8. **Container adapters**
* 9. **iterators as a concept**
* 10. **Tying it together**

## I) Why templates exist

Let's start with the actual problem before any syntax

Say we are writing C++98 and we need a ``max`` function that works for ``int`` and also for ``float``, and also for a class named ``Fixed``.

Wihtout anything called **Templates** we will write:

```
int max(int a, int b) {
    return (a > b) ? a : b;
}

float max(float a, float b) {
    return (a > b) ? a : b;
}

Fixed max(Fixed a, Fixed b) {
    return (a > b) ? a : b;
}
```

Same logic, copy-pasted three times, differing only in the type, this is a real problen for a few reasons:

1. **Maintenance**: if we find a bug in the logic, we have to fix it in N places

2. **It doesn't scale**: we can't predict every type someone will ever call ``max`` with, if a user of our code has their own ``Money`` class, they're stuck; we didn't write a ``max(Money, Money)``

3.**It's not actually generic**: the logic (``compare two things, return bigger``) has nothing to do with the type, the type is incidental.

We can find these two solutions before templates existed:

* **Macros**: (``#define Max(a, b)) ((a) > (b) ? (a) : (b))``) -- works for any type, but no type safety, no debugging support and classic double-evaluation bugs (``MAX(i++, j)`` increments ``i`` twice), pure text substitution.

* ``void*`` (C-style generic programming): we lose all type information, need manual casting, and the compiler can't catch type errors for us.

***
***Templates solve this differntly: they let us write the logic once, with the type as a parameter, and the compiler generates the specific version for each type we actually use, at compile time.***.
***

That last part "***at compile time***" is the key thing that seperates it from ``void*``, there's no runtime type-checking or casting overhead, the compiler literally writes ``max(int, int)``, ``max(float, float)``, etc. for us, as if we'd hand-typed each overload, but only for the types we actually call it with.

## II) Function Template -- Syntax and How it Works

Let's write the ``max`` function as an actual template

```
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

* ``template <typename T>`` -- this line declares that what follows is a template and ``T`` is a placeholder for a type, not a real type. It doesn't exist yet, think of it as a blank the compiler will fill in later.

* ``typename`` here, just means "T is a type"; We will also see ``class`` used interchangealy: ``template <class T>`` -- historically older syntax, means exactly the same thing as ``typename`` in this position, just stylistic choice.

* Everywhere ``T`` appears in the function afterward (``T a``, ``T b``, return type ``T``), it's a stand-in that gets replaced consistently with whatever real type is used when the function is called.

### Instantiation -- What actually happens when we call the templated function: 

```
int result = max(3, 5);
```

The compiler looks at the arguments (``3`` and ``5``, both ``int``), figures out ``T = int`` and then -- as if we had written it ourselves -- generates:

```
int max(int a, int b) {
    return (a > b) ? a : b;
}
```

This generation process is called **template instantiation**. It happens at **compile time**, not runtime, if we also call:

```
float result2 = max(3.5f, 2.1f);
```

The compiler generates a separate ``max(float, float)`` too. Call it with ``Fixed``, and we get ``max(Fixed, Fixed)``. Each distinct type we call it with produces its own compiled version. This is why there's zero runtime overhead  -- by the time our program runs, ``max<int>`` and ``max<float>`` are just two ordinary, fully-typed functions sitting in our binary. The "genericity" only existed at compile time, in our source code.

### Template Argument Deduction

Notice, we didn't write ``max<int>(3, 5)`` -- we just wrote ``max(3, 5)``. The compiler looked at the argument types and figured out ``T = int`` on its own. This called **templated argument deduction**.

We can be explicit if we want, or if the compiler can't figure it out from context:

```
int result = max<int>(3, 5);
int result2 = max<float>(3, 5); // forces float, even though the arguments are Ints
```

One more important notice -- deduction requires the types to match exactly (no implicit conversions during deduction):

```
max(3, 5.5); // ERROR: T deduced as int from first arg, double from the second one.
```

This fails because the compiler tries to deduce ``T`` from both arguments independently, gets ``int`` one and ``double`` from the other, and refuses to silently pick one and convert the other for us, we need ``max<double>(3, 5.5)`` or ``max(3.0, 5.5)``.

## III) Class Templates

Function templates generalize a function over a type. **Class templates** do the same for an entire class -- every memebr function, every memeber variable that uses ``T``, gets generated for whatever type we instantiate the class with.

Let's look at this minimal example -- a simple ``Box`` that holds one value of any type:

```
template <typename T>
class Box {
    private:
    T _value;

    public:
        Box(T value) : _value(value) {}
        T getValue() const { return _value; }
        void setValue (T value) { _value = value; }
};
```

Using it:

```
Box<int> intBox(42);
Box<std::string> strBox("hello");

std::cout << intBox.getValue() << std::endl; => 42
std::cout << strBox.getValue() << std::endl; => hello
```

### Key difference from function templates: No Deduction (Mainly in C++98)

Notice something important, with the function template, we wrote ``max(3, 5)`` and we let the compiler deduce ``T``. Here, we had to write ``Box<int>`` explicitly.

In C++98, class template never deduce the type from constructor arguments. We must alaways specifiy it: ``Box<int>``, ``Box<std::string>``, etc.

There's no way around this in C++98 -- the class name alone (``Box``) ins't a real type; ``Box<int>`` is the real type. The compiler needs ``<int>`` to know which class to even look up.

***Side Note***: this restriction was lifted in C++17 with "***class template argument deduction***".

## IV) The Compilation Model -- Why Templates Lives in Headers:

**Normal (non-template) compilatio recap**

For an ordinary function, we are used to this split:

```
// foo.hpp
int add(int a, int b); // declaration

// foo.cpp
int add(int a, int b) { // definition
    return  a + b;
}
```

``foo.cpp`` gets compiled **once**, independently, into ``foo.o`` -- actual machine code sits in that object file. Other ``.cpp`` files that ``#include "foo.hpp"`` just need the declaration to compile their calls to ``add()``; the linker later stitches the call to the actual machine code in ``foo.o``. This works because ``add``'s machine code deosn't depend on who's calling it -- it's fixed, one version, forever.

### Why this breaks for templates

```
// box.hpp

template <typename T>
class Box {
    private:
        T _value;
    public:
        T getValue() const { return _value; }
};
```

If we tried to compile ``box.cpp`` on its own like we normally do in case of ``foo.cpp`` example above; the compiler would hit a wall: **it doesn't know what ``T`` is yet. There is no machine code to generate for ``getValue()`` beacuse "return a ``T``" isn't a real instruction -- we can't generate assembly for a type that doesn't exist yet. ``T`` only becomes real at the moment someone, somewhere, writes ``Box<int>``.

So the compiler can't compile the template body in isolation the way it compiles ``foo.cpp``. It needs to see **both** the template definition **and** the specific type it's being instantiated with, **at the same time**, to generate real code.

### Templates must be visible where they're used

This means: wherever we write ``Box<int> b;``, the compiler needs the full template definition available right there -- not just a declaration. If the definition lived only in ``box.cpp``, and we ``#include "box.hpp"`` (declarations only) in ``main.cp`` the compiler compiling ``main.cpp`` would have no idea how to build ``Box<int>`` -- it only knows ``Box`` exists, not what it does.

This is why the convention is: **templates code goes in headers**, so it's visible in every translation unit that uses it.

## V) Non-Type Template Parameters

So far, every template has been a **type** (``typename T``).
But templates can also take an actual **Value** as parameter, known at compile time. That's a **non-type template parameter**.

```
template <typename T, int N>
class Array {
    private:
        T _data[N];
    public:
        int size() const { return N; }
};
```

Usage:

```
Array<int, 5> a // N = 5, baked in at compile time
Array<float, 10> b; // N = 10, a totally diifferent intantiated class than Array<int, 5>
```

The key thing: ``N`` isn't a variable -- it's a compile-time constant baked into the type itself, exactly like ``T`` is. ``Array<int, 5>`` and ``Array<int, 10>`` are two distinct, unrelated generated classes, the same way ``Box<int>`` and ``Box<float>`` were two distinct classes in the last section.
This is why we can do things like declare T _data[N] -- a fixed-size array -- because by the time the compiler generates this class, ``N`` is a known constant not a runtime value.

This matters for ``_data[N]`` specifically because C++98 arrays need a compile-time constant size -- we can't do ``T _data[some_runtime_variable]``. Non-type template parameters give us that compile-time constant, per-instantiation.

Restirctions worth knowing (C++98 era):
Non-type parameters must be integral types, enums, pointers or refrences not floats, not arbitrary objects, thus ``int, char, bool, unsigned long`` etc are finee; ``template <double D>`` is not allowed.

## VI) Multiple Template Parameters & Default Template Arguments

### Multiple Type Parameters

Nothing new conceptually -- just more than one ``T``

```
template <typename K, typename V>
class Pair {
    private:
        K _key;
        V _value;
    public:
        Pair(K key, V value) : _key(key), _value(value) {}
        K getKey() const { return _key; }
        V getValue() const { return _value; }
};
```

```
Pair<std::string, int> p ("age", 30);
```

Each parameter is deduced/specified independently. ``K`` and ``V`` can be the same type or different -- the compiler doesn't care, they're just two independent blanks to fill in.

### Default template arguments

Just like default function arguments, a template parameter can have a default

In oridnary C++ feature:

```
void greet(std::string name, std::string greeting = "Hello") {
    std::cout << greeting << "," << name << std::endl;
}
```

``greeting`` has a default value: ``"Hello"``, this means we can call this function in two ways:

```
greet("Xoris");
greet("Xoris", "Salut !"); // we explicitly override the Hello default value.
```

Just like that, Template also can have a defualt parameter we don't have to supply:

```
template <typename T, typename Container = std::vector<T> >
class Stack {
    Container _c;
}
```

Here, ``Container`` is a second template parameter -- but it has a default value: ``std::vector<T>`` this means:

```
Stack<int> s1;
```

We only supplied ``T = int``, we never touched ``Container`` at all -- so the compiler falls back to the default, and quietly instantiates this as if we write:

```
Stack<int, std::vector<int> > s1;
```

***Note***: it's ``std::vector<T>``, not a fixed type -- the default itself is written in terms of ``T``, so it adapts: if ``T = int``, the default becomes ``vector<int>``; if ``T = std::string`` it becomes ``vector<std::string>``.

But we can also override it explicitly, same as we would override any default function argument:

```
Stack<int, std::deque<int> > s2;
```

### Why this matters for ``std::stack``

This is the real, actual signature of ``std::stack`` in the standard library:

```
template <typename T, typename Container = std::deque<t> >
class stack;
```

So wehn we write ``std::stack<int> myStack;``, we never chose a conatainer -- but one was chosen for us: ``std:;deque<int>``, because that's ``std::stack``'s default.

This is why ``std::stack`` is described as being backed by a ``deque`` -- it's not a hardcoded rule, it's just what happens when we don't oevrride the second template parameter.

And this is why ``std::stack<int, std::vector<int> >`` is legal too -- we are just suppliying the scond parameter explicitly instead of taking the default.

