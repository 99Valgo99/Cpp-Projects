# CPP Module 06

![Logo](Img/cpp06.png)

#### ***Into The Type Of Casting in C++***
***

In C, when casting, we used for example ``(int)my_variable``, this is kindoff a sledehammer, it tells the complier to just do what i say.

C++ introduces **Named Castes** to add safety and intent, for this project we will look at ``static_cast``, but the main thing, is to understand what's happening in the underground.

### Implicit X Explicit Casting

* Implict (The "Safe" Path): When you move a smaller type to a larger type (``int`` to ``double``), the compiler does it automatically because no data is lost, this is called **Promotion**.

* Explicit (The "Risky" Path): When you move a larger type to a smaller type (``double`` to ``int``), you lose precision (the decimal part), C++ requires you to be explicit here to prove you know what you are doing.

### Static Cast: The Logic-Based Conversion

``static_cast<type>(expression)`` is used for conversions that can be checked during **compile-time**.

* **How it works**: it uses the built-in rules of the language, if you cast a ``float`` to an ``int``, the compiler generates code to truncate the value, if you cast a ``void *`` to a ``float *``, it trusts that you know what tha memory address points to.

* **Safery**: it won't let you cast completely unrelated types (like a ``Dog *`` to a ``Car *``), if the logic doesn't exist, the code won't compile.

### Bit-Level Reality (Under The Hood)

When you cast, one of two things happens in the hardware:

* **Value Transformation**: The bits actually change, an ``int`` representation of ``42`` looks nothing like the ``float`` representation of ``42.0f`` in binary, the CPU has to perform a calculation to transform one into the other.

* **Pointer Reinterpretation**: The bits stay the same, but your "lens" changes, if you have a memory address, ``static_cast`` might adjust that address, while ``reinterpret_cast`` would leave the address identical and just change how you "read" the data at that spot.