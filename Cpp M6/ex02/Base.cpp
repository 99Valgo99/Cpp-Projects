# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
    int random = std::rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else if (random == 2)
        return new C();
    else {
        std::cerr << "Memory Allocation Failed..." << std::endl;
        return NULL;
    }
}

void identify(Base *p) {
    std::cout << "*** Get type using Dynamic Cast Pointer ***" << std::endl;
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Type Of Object -> A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Type Of Object -> B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Type Of Object -> C" << std::endl;
} 

void identify(Base& p) {
    std::cout << "*** Get type using Dynamic Cast Reference ***" << std::endl;
    try {
        A& type1 = dynamic_cast<A&>(p);
        (void)type1;
        std::cout << "Type Of Object -> A" << std::endl;
    }
    catch (const std::exception& e) {
        try {
            B& type2 = dynamic_cast<B&>(p);
            (void)type2;
            std::cout << "Type Of Object -> B" << std::endl;
        }
        catch (const std::exception& e) {
            try {
                C& type3 = dynamic_cast<C&>(p);
                (void)type3;
                std::cout << "Type Of Object -> C" << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Unrecognized Type..." << std::endl;
            }
        }
    }
}
