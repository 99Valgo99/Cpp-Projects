# ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename FUNC> void iter(T* arr, const size_t length, FUNC F) {
    for (size_t i = 0; i < length; i++) {
        F(arr[i]);
    }
}

# endif