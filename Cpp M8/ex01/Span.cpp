# include "span.hpp"

Span::Span() {
    std::cout << "Default Constructor Called..." << std::endl;
    this->maxNumbers = 0;
}

Span::Span(unsigned int max_numbers): maxNumbers(max_numbers) {
    std::cout << "Parametrized Constructor Called..." << std::endl;
}

Span::Span(const Span& other) {
    std::cout << "Copy Constructor Called..." << std::endl;
    *this = other;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Copy Assignment Called..." << std::endl;
    if (this != &other) {
        this->v = other.v;
        this->maxNumbers = other.maxNumbers;
    }
    return *this;
}

Span::~Span() {
    std::cout << "Destructor Called..." << std::endl;
}

void Span::addNumber(int newNumber) {
    if (v.size() == maxNumbers)
        throw spanMaxError();
    v.push_back(newNumber);
}

int Span::shortestSpan() {
    
}

int Span::longestSpan() {
    
}

const char* Span::spanMaxError::what() const throw() {
    return "Max numbers are reached in the span...";
}

const char* Span::spanError::what() const throw() {
    return "No element in the span or only one element exist...";
}