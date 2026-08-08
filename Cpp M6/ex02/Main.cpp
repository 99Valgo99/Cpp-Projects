#include "Base.hpp"

int main() {

    std::srand(std::time(NULL));
    for (int i = 0; i < 3; i++) {
        Base *type = generate();
        if (type != NULL)
        {
            identify(type);
            identify(*type);
            delete type;
            std::cout << "--------------------------------------" << std::endl;
        }
        else
            return 1;
    }
    return 0;
}