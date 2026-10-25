# include "Array.hpp"

int main() {
    {
        // check Default Constructor/Desctructor
        Array<int> a;
    }
    std::cout << std::endl;
    {
        // check Params Constructor/Destructor
        Array<int> a(4);
    }
    std::cout << std::endl;
    {
        // checking [] Operator for Writing/Reading
        Array<int> a(3);
        for (unsigned int i = 0; i < a.size(); i++) {
            a[i] = i + 1;
            std::cout << "Array (a): " << a[i] << std::endl;
        }
        std::cout << "Array's (a) size: " << a.size() << std::endl;
    }
    std::cout << std::endl;
    {
        // checking Copy-Constructor Deep copy
        Array<int> a(3);
        for (unsigned int i = 0; i < a.size(); i++) {
            a[i] = i + 1;
            std::cout << "Array (a): " << a[i] << std::endl;
        }
        Array<int> b(a);
        for (unsigned int i = 0; i < b.size(); i++) {
            std::cout << "Array (b): " << b[i] << std::endl;
        }
        std::cout << "Array (b) size: " << b.size() << std::endl; 
        // modification in Array (b)
        b[2] = 11;
        std::cout << "Array's (b)[2]: " << b[2] << std::endl;
        std::cout << "Array's (a)[2]: " << a[2] << std::endl;
        // triggering the exception
        try {
            std::cout << "Out of Bounds index [11] in (b): " << b[11] << std::endl;
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        Array<int> x(3);
        for (unsigned int i = 0; i < x.size(); i++) {
            x[i] = i + 1;
            std::cout << "Array (x): " << x[i] << std::endl;
        }
        Array<int> y(1);
        y[0] = 11;
        std::cout << "y[0] -> " << y[0] << std::endl;
        y = x;
        for (unsigned int i = 0; i < y.size(); i++) {
            std::cout << "Array (y): " << y[i] << std::endl;
        }
    }
    std::cout << std::endl;
    {
        // testing Const-ness Of Operator method
        const Array<int> c(1);
        std::cout << "Const array first element: " << c[0] << std::endl;
        // c[0] = 1; will result in Const Writing Error
    }
    std::cout << std::endl;
    {
        // complex type: std::string
        Array<std::string> s(2);
        std::cout << "Default string element: [" << s[0] << "]" << std::endl;
        s[0] = "hello";
        s[1] = "world";

        Array<std::string> copy(s);
        copy[0] = "changed";
        std::cout << "s[0]: " << s[0] << " | copy[0]: " << copy[0] << std::endl;

        Array<std::string> assigned;
        assigned = s;
        s[1] = "mutated";
        std::cout << "s[1]: " << s[1] << " | assigned[1]: " << assigned[1] << std::endl;

        try {
            std::cout << s[2] << std::endl;
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}