# include "Span.hpp"

int main() {
    // subject test...
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    // triggering SpanMax Error Execption...
    std::cout << "*****************************" << std::endl;
    {
        Span Spanerror(0);
        try {
            Spanerror.addNumber(11);
        }
        catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << "*****************************" << std::endl;
    {
        unsigned int sizenumber = 5;
        Span Span1(sizenumber);
        std::vector<int> vector;
        for (unsigned int i = 0; i < sizenumber; i++) {
            vector.push_back(i);
        }
        try {
            Span1.addRangedNumber(vector.begin(), vector.end());
            std::cout << Span1.shortestSpan() << std::endl;
            std::cout << Span1.longestSpan() << std::endl;
        }
        catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << "*****************************" << std::endl;
    // testing SpanError Exception
    {
        Span Spanerror2(1);
        try {
            Spanerror2.addNumber(11);
            std::cout << Spanerror2.longestSpan() << std::endl;
        }
        catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << "*****************************" << std::endl;
    // stress test with 10.000 number
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<int> stress_vector;
    for (int i = 0; i < 10000; i++)
        stress_vector.push_back(std::rand() % 100000);
    Span Spanstress(10000);
    try {
        Spanstress.addRangedNumber(stress_vector.begin(), stress_vector.end());
        std::cout << Spanstress.shortestSpan() << std::endl;
        std::cout << Spanstress.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}