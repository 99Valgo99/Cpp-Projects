#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    std::vector<int> v;
    v.push_back(4);
    v.push_back(8);
    v.push_back(15);
    v.push_back(16);

    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 15);

    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found" << std::endl;

    // same call shape, different container
    std::list<int> l;
    l.push_back(23);
    l.push_back(42);

    std::list<int>::iterator lit = std::find(l.begin(), l.end(), 99);

    if (lit != l.end())
        std::cout << "Found: " << *lit << std::endl;
    else
        std::cout << "Not found" << std::endl;

    return 0;
}