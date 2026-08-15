# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>


class cantFind404 : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "The Specified Value Cannot Be Found...";
        }   
};


template <typename T> typename T::iterator  easyfind(T& cont, int integer) {
    typename T::iterator finder = std::find(cont.begin(), cont.end(), integer);
    if (finder == cont.end())
        throw cantFind404();
    return (finder);
}

template <typename T> typename T::const_iterator easyfind(const T& cont, int integer) {
    typename T::const_iterator finder = std::find(cont.begin(), cont.end(), integer);
    if (finder == cont.end())
        throw cantFind404();
    return (finder);
}

# endif