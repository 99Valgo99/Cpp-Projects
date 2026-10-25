# include "Span.hpp"

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
    std::cout << "Adding Numbers..." << std::endl;
    if (v.size() == maxNumbers)
        throw spanMaxError();
    v.push_back(newNumber);
}


long Span::shortestSpan() {
    std::cout << "Looking For The ShortestSpan..." << std::endl;
    if (v.size() < 2)
        throw spanError();
    std::vector<int> v_cpy(v);
    std::sort(v_cpy.begin(), v_cpy.end());
    long shortest_value = static_cast<long>(v_cpy[1]) - static_cast<long>(v_cpy[0]);
    for (std::vector<int>::iterator it = v_cpy.begin() + 2; it != v_cpy.end(); ++it)
        shortest_value = std::min(shortest_value, static_cast<long>(*it) - static_cast<long>(*(it - 1)));
    return (shortest_value);
}

long Span::longestSpan() {
    std::cout << "Looking For The LongestSpan..." << std::endl;
    if (v.size() < 2)
        throw spanError();
    long max_value = static_cast<long>(*(std::max_element(v.begin(), v.end())));
    long min_value = static_cast<long>(*(std::min_element(v.begin(), v.end())));
    return (max_value - min_value);
}

const char* Span::spanMaxError::what() const throw() {
    return "Max numbers are reached in the span...";
}

const char* Span::spanError::what() const throw() {
    return "No element in the span or only one element exist...";
}

unsigned int Span::maxNumbersGetter() const {
    return (this->maxNumbers);
}