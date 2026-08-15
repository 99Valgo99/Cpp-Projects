# CPP Module 08

This module is about ***Templated containers, iterators, algorithms***.

## Containers

A container is a class template that stores a collection of objects and manages their memory for us -- no manual ``new``/``delete``.

```
# include <vector>
# include <list>

std::vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);
// v now holds { 10, 20, 30 }, contiguous in memory

std::list<int> l;
l.push_back(10);
l.push_back(20);
l.push_back(30);
// l holds the same values, ut as linked nodes scattered in memory.
```

Both ``v`` and ``l`` store the same three ints, but internally they're built completely diffrently.

* ``vector`` -- one contiguous block of memory, like a dynamic array. Random access (``v[1]``) is O(1). Inserting/removing in the middle is expensive (everything after has to shift).

* ``list`` -- a doubly-linked list of seperate heap nodes, each pointing to the next and previous, no random acccess via index, insert/remove anywhere is O(1) once we are at the right spot.

Different memory layout, different performance trade-offs -- but as far as the code that uses them is concerned, we can treat them the same way, that's the point of conatainer abstraction.

### Containers Families:

1. **Sequence Containers** ordered by position, not by value.

* ``vector`` -- contiguous array, fast random access, slow insert/erase in the middle.
* ``list`` -- doubly-linked list, fast insert/erase anywhere, no random access.
* ``deque`` -- double-ended queue, fast push/pop at both ends.

2. **Associative Containers** ordered/hashed by key, not insertion order.

* ``map``, ``set``... -- we won't need these for the ex00 (subject says so explicitly).


## Iterators

The problem; if ``vector`` and ``list`` are laid out out in memory so diffrently, how can the same piece of code ("gp through every element") work on both ?

The answer is the iteraator -- an object that knows how to move from one element to the next, however that container is actually organized underneath.

```
std::vector<int>::iterator vit;
for (vit = v.begin(); vit != v.end(); ++vit)
    std::cout << *vit << std::endl;

std::list<int>::iterator lit;
for (lit = l.begin(); lit != l.end(); ++lit)
    std::cout << *lit << std::endl;
```

Same loop shape, same operations (``*``,``++``, ``!=``), same result printed -- but deep down:

* ``vector<int>::iterator`` is, conceptually, just a pointer. ``++vit`` literally does pointer arithemtic (``ptr + 1``).

* ``list<int>::iterator`` is a small class wrapping a pointer to a linked-list node. ``++lit`` follows that node's ``next`` pointer to jump to the next node, wherver it lives in memory.

Two totally different implementations, exposed through one identical interface: ``*it`` to read the element, ``++it`` to move forward, ``it != container.end()`` to know when to stop.

``begin()`` gives us an iterator at the first element, ``end()`` gives us an iterator to one-past-the-last-element -- a sentinel, not a real element, so we never dereference it, only compare against it.

This shared interface is exactly what lets a generic algortihm like ``std::find(first, last, value)`` work on a ``vector``, a ``list``, or amything else with ``begin()``/``end()`` -- it never needs to know which one it got.


### Exercise I

We will work on creating a function template that works with different **Containers** (List && Vectors), since both of these containers are equipped with **Iterators**, we can use that in our advantage to create a blueprint template function that works for all of them.

The signature for this Template function named ``easyfind`` goes as such:

```
template <typename T> typename T::iterator easyfind(T& container, int integer) { }
```

Without ``typename`` before ``T::iterator``, the compiler would treat it as value by default (like looking for a static memeber or a function) rather than a type, since ``T`` is a template parameter, the compiler cannot know whether ``iterator`` is a type or value until instantiation, thus ``typename`` explicitly tells the compiler to treat it as a type.