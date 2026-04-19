## CPP Module 05
***

This Module is about ***Exceptions***.
With a deep dive into **Error handling** and **Class Design** in ``C++``.

In ``C`` Language, error handling is manual, we return ``-1`` or ``NULL`` and check for it and do what we will based on the context of the code and the program, this makes the code vulnerable to **Leaks** and **Crashes** (Segfaults).

However, in ``C++`` exceptions are here to make error handling mandatory, you cannot easily ignore an exception, if you don't catch it, the program dies, this is "fail-fast" behavior, which is more safer than "Silent Corruption".

When using exepctions, mainly the ``throw`` keyword, it calls the C++ ABI **(Application Binary interface)**, a **Memory Allocation** occurs, the compiler generates a call to a function ``__cxa_allocate_exception``, this creates a special "exception object" in a dedicated memeory area.
Then the CPU stops executing our code and jumps into the C++ Runtime Library, the runtimes **Freezes** the state of the CPU, it records the current value of the **Instruction Pointer** (IP) and the **Stack Pointer**, it needs this IP to look up the **Unwind Tables**