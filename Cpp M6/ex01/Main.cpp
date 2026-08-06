#include "Serializer.hpp"

int main() {
    Data Backup;

    Backup.data_1 = "TEXT 1 !";
    Backup.data_2 = "TEXT 2 !";

    std::cout << "DATA_1 -> " << Backup.data_1 << std::endl;
    std::cout << "DATA_2 -> " << Backup.data_2 << std::endl;

    uintptr_t encoded = Serializer::serialize(&Backup);
    std::cout << "Pointer Interpreted as UINT -> " << encoded << std::endl;

    Data* decoded = Serializer::deserialize(encoded);

    if (decoded == &Backup)
        std::cout << "Same Data has been encoded and decoded..." << std::endl;
    std::cout << "DATA_1 -> " << decoded->data_1 << std::endl;
    std::cout << "DATA_2 -> " << decoded->data_2 << std::endl;

    return 0;
}