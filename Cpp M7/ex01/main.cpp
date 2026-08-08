# include "iter.hpp"

void decre(int& x) { x--; }

void incree(int& y) { y++; }

void outPut(const int& z) {
    std::cout << "Arr -> " << z << std::endl;
}

int main() {

    int arr[] = {0, 1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    ::iter(arr, length, outPut);

    std::cout << "Decrementing using Decree Function" << std::endl;
    ::iter(arr, length, decre);
    
    ::iter(arr, length, outPut);
    ::iter(arr, length, incree);
    std::cout << "Incrementing using Incree Function" << std::endl;
    ::iter(arr, length, outPut);

    return 0;
}