# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class Array {
    private:
        T* info;
        unsigned int infosize;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array& operator=(const Array &other);
        ~Array();

        T& operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        unsigned int size() const;

        class oTB : public std::exception {
            public:
                const char *what() const throw() {
                    return "Error: Index Is Out Of Bounds...";
                }
        };
};

# include "Array.tpp"

# endif