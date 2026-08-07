# CPP Module 07

![Logo](Img/cpp07.png)

This Module is about ***Templates*** In C++.
***

Before ***Templates***, if we wanted a ``max`` function that worked on ``int``, ``float`` and ``std::string``, we will have to write three overloads with identical logic, just different types, that's copy-paste with only the type changed -- exactly the kind of repetition compilers should handle for us.

### What a template actually is
```
template <typename T>
T max(T a, T b) {
    return (a > b) ? b : a
}
```

``template <typename T>`` isn't a function -- it's a ***blueprint**.
``T`` is a placeholder type, filled in later. No code is generated yet.

### Instantiation -- The Key Concept

Code only gets generated when we use the template with a concrete type:

```
max(3, 5); // compiler generates max<int>
max(3.14, 2.71) // compiler generates max<double>
```

This happens at ***compile time***, not runtime, the compiler looks at our call, deduces ``T``, and stamps out a real function -- as if we'd hand-written ``max<int>`` and ``max<double>`` ourselves.
This is called ***Implicit instantiation***.

Consequence: if we never call ``max<std::string>``, that version never gets compiled, never gets checked, doesn't even exist in our binary. Templates are lazy.

### Type Deduction

We usually don't write ``max<int>(3, 6)`` -- the compiler deduces ``T`` from the arguments, but deduction requires **both argument to resolve to the same T**.

```
max(3, 3.5) // ERROR: T deduced as int from first arg, and double from second one.
```

This connects directly to the subject's line:
***"the two argyments must have the same type"***.
Now we know exactly why that constraint exists, it's not arbitrary, it's a deduction limitiation.

### Where templates must live

Templates must be **fully defined in the header**, not split into a ``.cpp``.
* Why: instantiation happens at compile time, in the translation unit that uses the template, if the definition were hidden in a seperate ``.cpp``, the compiler at the call site would only see a declaration -- no body to instantiate from, so ``template`` ode = header-only (or .``.tpp`` included at the bottom of the header, which we will see and use in ex02). 