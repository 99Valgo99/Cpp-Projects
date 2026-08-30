# include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack() {
    std::cout << "Default Constructor Called..." << std::endl;
}

template <typename T> MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {
    std::cout << "Copy Constructor Called..." << std::endl;
}

template <typename T> MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    std::cout << "Assignment Operator Called..." << std::endl;
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template <typename T> MutantStack<T>::~MutantStack() {
    std::cout << "Destructor Called..." << std::endl;
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}