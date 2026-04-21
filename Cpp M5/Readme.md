## CPP Module 05

![Logo](Img/cpp05.png)
***

This Module is about ***Exceptions***.
With a deep dive into **Error handling** and **Class Design** in ``C++``.

In ``C`` Language, error handling is manual, we return ``-1`` or ``NULL`` and check for it and do what we will based on the context of the code and the program, this makes the code vulnerable to **Leaks** and **Crashes** (Segfaults).

However, in ``C++`` exceptions are here to make error handling mandatory, you cannot easily ignore an exception, if you don't catch it, the program dies, this is "fail-fast" behavior, which is more safer than "Silent Corruption".

When using exepctions, mainly the ``throw`` keyword, it calls the C++ ABI **(Application Binary interface)**, a **Memory Allocation** occurs, the compiler generates a call to a function ``__cxa_allocate_exception``, this creates a special "exception object" in a dedicated memeory area.
Then the CPU stops executing our code and jumps into the C++ Runtime Library, the runtimes **Freezes** the state of the CPU, it records the current value of the **Instruction Pointer** (IP) and the **Stack Pointer**, it needs this IP to look up the **Unwind Tables**
***
### KeyConcepts

* ***Instruction Pointer (IP)***: This is the CPU's "Now Reading" marker, it holds the memory address of the very next machine instruction to be executed.
* ***Stack Pointer (SP)***: This points to the "top" of the current stack frame, it tracks where our local variables are living in memory.

When we ``throw`` an exception, the **ABI (Application Binary Interface)** takes over, it looks at the **Instruction Pointer** and look if ***At this specific memory address, are we inside a ``try`` block?***.

it checks the **Unwind Tables** (compiled into the code's binary), these tables are essentially a map:

***"if the IP is between address ``0x123`` and ``0x456``, there is a handler at ``0x789``"***
***

### Stack Unwinding: The Cleanup Crew

If the ABI deterimines the current function doesn't have a ``catch`` block for that exception, it must **Unwind**, this is the most critical part of C++ exceptions.

***Stack Unwiding*** is the process of:

* Moving the **Stack Pointer** up to the previous function's frame.
* Crucially: Calling the **Destructors of the automatic (stack) objects in the scope being exited.

Let's take this example (Given by GeminiAi)

```
void fosterBureaucracy() {
    Bureaucrat bob("Bob", 2);
    bob.incrementGrade(); // This becomes 1
    bob.incrementGrade(); // This throws GradeTooHighException!
    // Any code here is skipped
}
```

When the ``throw`` happens, the **ABI** ensures that ``bob``'s destructor is called before moving to the ``catch`` block in the ``main``, in C, if you just ``return (-1)``, you might forget to free memory or close files, in C++, **Unwinding** makes this automatic.

### ABI and the Personality Routine

The **ABI** is the "legal agreement" on how functions call each other, for exceptions, it defines a **Personality Routine**.

* **Phase I** (Sreach): The runtime scans the stack to see if anyone can catch this exception, if no one can, it calls ``std::terminate()`` immediately (The program Crashes).
* **Phase II** (Cleanup): If a handler is found (''catch''), the runtime scans the stack second time, actually running destructors and finally reseting the *IP* to the address of the ``catch`` block.
***
### Recap

**1. The Trigger**: When ``throw`` is execued, the COU doesn't just "Jump", it hands control to the **Personality Routine**.

**2. The Exception Object**: Unlike our local ``Bureaucrat bob`` who lives on the stack and gets destroyed during unwinding, the **Exception Object** (The thing we ``threw``) lives in a "Side-Channel" memory area (Often managed by ``__cxa__allocate_exception``), this is why you can catch it after the stack frame where it was created has been destroyed.

**3. The Two-Pass System**:

* Pass 1 (Search): The **ABI** uses the IP and Unwind Tables to find a matching ``catch``
* Pass 2 (Cleanup): The **ABI** uses the SP to physically pop frames and run destructors.
***

### Practice Makes Perfect

In ``C++``, the standard and known way to use the exceptions in the case of our exersices, is to define them as **Inner Classes** inside of the main class in our cass:

* ***Bureaucrat*** (Outer Class)
    
    * ***GradeTooHighException (Inner Class)***

    * ***GradeTooLowException (Inner Class)***

Both **Inner Classes** inherits from ``std::exception``.

When we use ``catch (std::execption & e)``, we are holding a net, any object that is a ``std::exception`` (via **Inheritance**) will fall into that net.

Since ``GradeTooHigh/LowException`` inherits from ``std::exception``, it can "wear the mask" of its parent

The ``std::exception`` has **Virtual Table Pointer** present due to having a function called ``what()``, we have to override this function in our **Inner Class** in order to display our custom error and message.

Therefore when the code hits ``catch (std::exception &e)``, the compier does not know which exception was thrown (it could be ours, a ``std::bad_alloc`` or a ``std::runtime_error``).

Using **Dynamic Dispatch** at runtime, the compiler looks at object ``e``, follows the **Vptr** to the **Vtable** of the actual class that was thrown, it finds the address of ``what()`` function specifically for that class (our overriden function of ``what``).

#### Why should we use a Reference (& e) ?

If we catch the exception without the ``&`` Reference symbol, a memory of (8 byte) will be allocated for ``std::exception``, when we throw our custom exception ``GradeTooHigh/LowException``, C++ tires to "copy" it into that 8 byte-box, which cannot fit, so it simply chops off (**Slices**) everything that doesn't fit, including the custom ``what()`` function, the object is "Downgraded" or "demoted" to a plain old ``std::exception``, Resulting in **Object Slicing**.
***