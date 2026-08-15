# include "easyfind.hpp"

int main() {
    std::vector<int> v;
    std::cout << "Vector: " << std::endl;
    for (int i = 0; i < 11; i++) {
        v.push_back(i);
        for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
            std::cout << " " << *it;
        std::cout << std::endl;
    }
    try {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Value Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error:" << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 111);
        std::cout << "Value Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "*********************************************\n";

    std::list<int> l;
    std::cout << "List: " << std::endl;
    for (int i = 0; i < 11; i++) {
        l.push_back(i);
        for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
            std::cout << " " << *it;
        std::cout << std::endl;
    }
    try {
        std::list<int>::iterator it = easyfind(l, 144);
        std::cout << "value Found: " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::list<int>::iterator it = easyfind(l, 4);
        std::cout << "Value Found: " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "*********************************************\n";
    std::vector<int> temp_vector;
    for (int i = 0; i < 5; i++) {
        temp_vector.push_back(i);
    }
    const std::vector<int> v2(temp_vector);
    for (std::vector<int>::const_iterator it = v2.begin(); it != v2.end(); ++it)
        std::cout << " " << *it << std::endl;
    try {
        std::vector<int>::const_iterator it = easyfind(v2, 1);
        std::cout << "value Found: " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}