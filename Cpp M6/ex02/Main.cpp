#include "Base.hpp"

int main() {

    std::srand(std::time(NULL));
    for (int i = 0; i < 3; i++) {
        Base *type = generate();
        identify(type);
        delete type;
    }
}