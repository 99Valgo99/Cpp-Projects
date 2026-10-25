# include "iter.hpp"

void decre(int& x) { x--; }

void incree(int& y) { y++; }

void outPut(const int& z) {
    std::cout << "Arr -> " << z << std::endl;
}

template <typename T> void printElem(const T& elem) {
    std::cout << "Elem -> " << elem << std::endl;
}
 
void exclaim(std::string& s) {
    s += "!";
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


    std::cout << "Const array with an instantiated function template" << std::endl;
    const int carr[] = {10, 20, 30};
    (void)carr;
    // ::iter(carr, 3, printElem<int>);
    // ::iter(carr, 3, incree); would not compile: elements are const
 
    std::cout << "String array: read, modify, read again" << std::endl;
    std::string words[] = {"hello", "world", "iter"};
    size_t wlen = sizeof(words) / sizeof(words[0]);

    ::iter(words, wlen, printElem<std::string>);
    ::iter(words, wlen, exclaim);
    ::iter(words, wlen, printElem<std::string>);
 
    return 0;
}