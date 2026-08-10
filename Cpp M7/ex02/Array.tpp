#include "Array.hpp"

template <class T> Array<T>::Array() : info(0), infosize(0) {
    std::cout << "Default Constructor Called..." << std::endl;
}

template <class T> Array<T>::Array(unsigned int n): infosize(n) {
    std::cout << "Parametrized Constructor Called..." << std::endl;
    info = new T[n]();
}

template <class T> Array<T>::Array(const Array &other): info(0), infosize(0) {
    std::cout << "Copy Constructor Called..." << std::endl;
    *this = other;
}

template <class T> Array<T>& Array<T>::operator=(const Array &other) {
    std::cout << "Assignement Operator Called..." << std::endl;
    if (this != &other) {
        delete[] this->info;
        this->infosize = other.infosize;
        this->info = new T[this->infosize];
        for (unsigned int i = 0; i < infosize; i++) {
            this->info[i] = other.info[i];
        }
    }
    return *this;
}

template <class T> Array<T>::~Array() {
    std::cout << "Destructor Called..." << std::endl;
    delete[] info;
}

template <class T> T& Array<T>::operator[](unsigned int index) {
    if (index >= infosize)
        throw oTB();
    return info[index];
}

template <class T> const T& Array<T>::operator[](unsigned int index) const {
    if (index >= infosize)
        throw oTB();
    return info[index];
}

template <class T> unsigned int Array<T>::size() const {
    return (this->infosize);
}