# ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T0> void swap(T0& x, T0& y) {
    T0 temp_z = y;
    y = x;
    x = temp_z;
}

template <typename T1> T1& min(T1& x, T1& y) {
    if (y > x)
        return x;
    return y;
}

template <typename T2> T2& max(T2& x, T2& y) {
    if (x > y)
        return x;
    return y;
}

# endif