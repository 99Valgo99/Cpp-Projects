# include "Array.hpp"

int main() {
    {
        // Check Default Constructor/Desctructor
        Array<int> a;
    }
    std::cout << std::endl;
    {
        // Check Params Constructor/Destructor
        Array<int> a(4);
    }
    std::cout << std::endl;
    {
        // Checking [] Operator for Writing/Reading
        Array<int> a(3);
        for (unsigned int i = 0; i < a.size(); i++) {
            a[i] = i + 1;
            std::cout << "Array (a): " << a[i] << std::endl;
        }
        std::cout << "Array's (a) size: " << a.size() << std::endl;
    }
    std::cout << std::endl;
    {
        // Checking Copy-Constructor Deep copy
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
        // Modification in Array (b)
        b[2] = 11;
        std::cout << "Array's (b)[2]: " << b[2] << std::endl;
        std::cout << "Array's (a)[2]: " << a[2] << std::endl;
        // Triggering the exception
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
        // Testing Const-ness Of Operator method
        const Array<int> c(1);
        std::cout << "Const array first element: " << c[0] << std::endl;
        // c[0] = 1; will result in Const Writing Error
    }
    return 0;
}