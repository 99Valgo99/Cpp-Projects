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

### Usage

We make the two classes inherit from ``std::exception``:

```
class Classes : public std::exception {}
```

Then we override the ``what()`` function to our implementation, instead of the one from ``std::exception``:

```
virtual const char* what() const throw();
```

* ``virtual``: This is the keyword that turn the **Dynamic Dispatch** On.
* ``const char*``: the function returns a pointer to a string, this is the standard way C++ exceptions report their error messages.
* ``const``: This guarantees that calling ``what()`` won't change the exception object itself.
* ``throw()``: This is an **exception specification**, it's a promise that ``throw`` function will not throw an exception of its own.

Example from Gemini, as why the ``const`` & ``throw()`` keywords are important:

```
const char* what() const throw() {
    this->grade = 10; // ERROR: 'const' forbids this!
    throw std::runtime_error("oops"); // TERMINATE: 'throw()' forbids this!
    return "Success";
}
```
How the implementation of the custom ``what()`` function goes:

```
const char* Class::ClassExepction::what() const throw {
    return "Testing Exceptions...";
}
```
***
***Notes***:

* Since we are returning a **string literal**, it gets stored in "Read-Only" memory area of the program (**Data Segment**), which means if the program is crashing or the stack is being "unwound", this message is safely destroyed, with no memory allocation left overs.

* We should not ``catch`` an exception after ``throwing`` it inside of a **Constructor**, this will result on an undefined behavior, if we throw an exception and catch it inside of the constructor, we might print ``Error`` yet, the execution continues, making C++ runtime thinking that the object is now valide and constructed, therefore calling something like ``bureaucrat.gradeIncrement()`` may result in a crash or unexpected behavior, since the object exists in memeory but the grade that's built upon the validation of the ``exception`` contains unintialized garbage.
***

### The Form Header & Bureaucrat Header ErrorLoop

The issue we will face in this section, mainly in **Ex01** is pointing toward the concepts of **Circular Dependencies** and **Forward Declarations**, beside that this exercise is all about logic handling and raw coding of **Exceptions**.

In this exercise, we encounter this issue:

* ***The Bureaucrat*** needs to know about the **Form** to have a function called ``signForm(Form &form)``.
* ***The Form*** needs to know about the **Bureaucrat** to have a function called ``beSigned(const Bureaucrat &buro)``.

If you try to ``#include`` each header into the other, we face this issue:

* 1) The compiler starts with the ``main.cpp``, it sees ``#include "Bureaucrat.hpp``, the preprocessor opens it & defines the macro ``BUREAUCRAT_HPP``, inside of it, it sees ``#include "Form.hpp"``, it pauses reading the ``Bureaucrat.hpp`` and jump to ``Form.hpp``.

* 2) The compiler now defines ``FORM_HPP``, looks inside it and sees ``#include "Bureaucrat.hpp``, it tries to jump back to it, it looks at it and finds the **Header Guard** ``#ifndef BUREAUCRAT_HPP``, therefore it skips it.

* 3) The preprocessor returns to ``Form.hpp`` and continues reading, it finds ``void beSigned(const Bureaucrat& Buro)`` and **crashes** since it does not know about the Bureaucrat class because it stopped at the top of the header file of ``Bureaucrat.hpp`` when it encountered ``#include Form.hpp``.

#### To solve this problem, we use ***Forward Declaration***:

When we replace the ``#include`` with only ``class Bureacrat;``, we change the compiler's requirement for "Full knowledge" to "Basic Awareness".

* A Definition via ``#include`` tells the compiler the **Size** and **Members**, the compiler needs this to create an object on the **Stack** because it must know excatly how many bytes to reserve.
* A Declaration via ``class X;`` only tells the compiler the **Name**.

And because the size of a reference is constant (8 Bytes), the compiler doesn't need to know what's inside of the ``Bureaucrat`` class to compile a function signature like ``void beSigned(Bureaucrat& Buro)``, it just reserves the 8 bytes for an address, and trust the promise that a class with that specifed name exists somewhere else.

#### The Final Piece

When the compiler finishes turning the ``.cpp`` files into object files ``.o``, it leaves notes for the **Linker**.

* In ``Form.o``, it says; There is a function named ``beSigned``, i don't know where it is, but i know it takes a reference.
* In ``Bureaucrat.o``, it says; I have the actual code for ``Bureaucrat`` and its methods.

The **Linker** then uses those instructions to actually link the address of the **Bureaucrat** into the holes left from the **Form** code.
***

### The Template Method Pattern (``Exercise02``)

The **Template Method Pattern** is a behavioral design pattern that defines the ***Skeleton*** of an algorithm in a base class (**The Template**), but lets subclasses override specific steps of the algorithm without changing its overall structure.

#### Core Atchitecture

Think of the base class as a **Project Manager** and the subclasses as **Specialists**.

* **The Template Method** (``AForm:execute``): This is a public, non-virtual function in the base class, it defines the ***Order Of Operations***, it handles the logic that is universal to all forms (***Checking if the form is signed and if the grade is high enough***)

* **The Primitive Operations** (``executeAction``): These are protected, pure virtual functions, the base class doesn't know how to do these steps; it only knows when they should happen.

#### Why We Use It Here

Without this pattern, you would have to check the verifications step of the Form on each one of the subclasses, which means if **The Logic** changes, you will have to change it in a three different files which equals **Weak Maintenance**, also it might lead to **Security Issues**, a Developer might add another subclass forgetting to implement the verifications steps allowing a low-level Bureaucrat to execute it.

This patterns follows the "***Don't call us, we'll call you***" Rule, 
The subclasses don't call the base class to check the requirements, instead, the base class checks the requirements and then "***Calls Down***" into the subclass to perfom the specific action.

#### Abstract Breakdown & Architectual Pattern: Template Method

To ensure strict bureaucratic oversight, we need to make sure these three concepts are implemented:

* **Standardization**: The base class ``AForm`` provides a public ``execute()`` function that acts as a mandatory wrapper, it handles the "***Universal Rules***" (Checking signature status & grade requirements).

* **Specialization**: Once the requirments are validated, ``AForm`` calls a protected pure virtual function ``executeAction()``.

* **Encapsulation**: This structure ensures that concrete forms, only contain the logic relevant to their specefic tasks, while the safety checks remain centralized and immutable in the base class.