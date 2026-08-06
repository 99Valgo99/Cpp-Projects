#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serialize Default Constructor Called..." << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    std::cout << "Serialize Copy Constructor Called..." << std::endl;
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    std::cout << "Serialize Assignement Operator Called..." << std::endl;
    (void)other;

    return *this;
}

Serializer::~Serializer() {
    std::cout << "Serialize Destructor Called..." << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t decoded) {
    return reinterpret_cast<Data*>(decoded);
}