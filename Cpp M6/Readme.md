# CPP Module 06

![Logo](Img/cpp06.png)

#### ***Into The Type Of Casting in C++***

In C, when casting, we used for example ``(int)my_variable``, this is kindoff a sledehammer, it tells the complier to just do what i say.

C++ introduces **Named Casts** to add safety and intent, for this project we will look at ``static_cast``.
***

In C, we had one tool ``(type)expression``, it does whatever it can -- reinterpret bits, convert, strip ``const`` -- silently, without telling you which one it just did, C++ splits that single blunt tool into four named operator, each with a narrow checkable job, the compiler enforces what each one is allowed to do, so a bad cast fails to compile instead of failing silently at runtime.

### I. ``static_cast<T>(expr)``

The "sane, everyday" cast, used for conversions that are well-defined and related at compile time:
``int`` -> ``float``, ``int`` -> ``char``.
base-class pointer -> derived-class pointer (without runtime safety check) or calling an explicit constructor, if the compiler can reason about the relationship between the two types, ``static_cast`` is the tool, it will not let us cast between two totally unrelated pointer types.

When we cast ``static_cast`` a ``Base*`` to a ``Derived *``, the compiler checks one thing only: is ``Derived`` actually related to ``Base`` in the class hierarchy? if yes, it compiles -- the cast is allowed, but it does not check whether the object you've actually pointing to, right now, at runtime is a ``Derived``;

so this compiles fine and is completely valid:

```
Base* b = new Derived();
Derived* d = static_cast<Derived*>(b); // fine - b really pointing to a Derived.
```

But this also compiles, and is a ticking bomb:

```
Base* b = new Base(); // this is really just a Base
Derived* d = static_cast<Derived*>(b); // compiles ! compiler trusts you
d->DerivedMethod(); // undefined behavior -- can't treat a Base as a Derived.
```

### II. ``dynamic_cast<T>(expr)``

The safe cast for polymorphic class hierarchies (classes with at least one ``virtual`` function), it performs a **runtime** check:
***"is the object pointed to actuall a ``Derived`` or just a ``Base``?"***, if we cast a pointer and it fails, we get ``nullptr``, if we cast a reference and it fails, it throws ``std::bad_cast``, this is the only cast that does real work at runtime rather than just at compile time.

### III. ``const_cast<T>(expr)``

Only job: add or remove ``const`` (or ``volatile``), nothing else -- we can't change the underlying type, mostly used to interface with legacy APIs that aren't ``const``-correct, using it to then modify something that was originally declared ``const`` is undefined behavior -- it only legitimately strips constness on data that wasn't actually const to begin with.

Let's say in this scenario, we have this old C-style function that was never updated to be ``const``-correct, even though it doesn't modify anything:

```
void printLength(char *str) {
    std::cout << strlen(str) << std::endl;
}

void greet(const std::string& name) {
    const char* cstr = name.c_str();
    printLength(cstr); // ERROR: printLength expects raw char* str not const.
}
```

``name.c_str()`` gives us a ``const char*`` (we are not allowed to modify a ``std::string``'s internal buffer), but ``printLength`` demands a plain ``char *``, even though it only reads the string, we know it by inspecting its implementation, thus we can strip the ``const`` just to satisfy the compiler's type-matching, using ``const_cast``:

```
printLength(const_cast<char*>(cstr));
```

In this case ``printLength`` does not modify anything, real danger if it did, in this case, undefined behavior occurs, because the underlying data really is ``const``, ``const_cast`` doesn't change that fact, it only lets you lie to the type system about it.

### IV. ``reinterpret_cast<T>(expr)``

The dangerous one, Reinterprets the raw bits of one type as another, unrelated type -- e.g, pointer -> integer, or ``Foo*`` to ``Bar*``, where ``Foo`` and ``Bar`` have nothing to do with each other, no safety check, no conversion logic, just ***"Trust me, treat these bytes as this other type"***, this is our tool for ``ex01`` (pointer -> ``uintptr_t``).

### Coding Example for the types

