# CPP Module 08

This module is about ***Templated containers, iterators, algorithms***.

## STL Containers -- The Core Idea

A **container** is a class template that manages a collection of objects.
Every standard container gives us a consistent interface, so algorithms and generic code (like ``easyfind``) can work on any of them without caring which one it is.

### Two Broad Families:

1. **Sequence containers** -- ordered by position, not by value.

* ``vector`` -- contiguous array, fast random access, slow insert/erase in the middle.
* ``list`` -- doubly-linked list, fast insert/erase anywhere, no random acess.
* ``deque`` -- double--ended queue, fast push/pop at both ends.

2. **Associative containers** -- ordered/hashed by key, not insertion order.
* ``map``, ``set``, etc... -- we won't need these for the first exercise in this Module.

3. **Container adapters** -- not real containers, they wrap one and restrict its interface