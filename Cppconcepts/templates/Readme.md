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

