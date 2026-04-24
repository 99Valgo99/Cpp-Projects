# include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Buro;
    std::cout << Buro << std::endl;
    std::cout << "**--------------------------------**\n";
    std::cout << std::endl;
    try
    {
        Bureaucrat Buro2("Buro2", 150);
        std::cout << Buro2 << std::endl;
        std::cout << "** Decrementing The Grade For Buro... **\n";
        Buro.gradeDecrement();
        std::cout << std::endl;
        std::cout << "**--------------------------------**\n";
        std::cout << std::endl;
        
        std::cout << "** Double Incrementing The Grade...\n";
        Buro.gradeIncrement(); Buro.gradeIncrement();
        std::cout << "** If The Exception Has Been Thrown, You Wont See This Message... **\n";
        std::cout << Buro << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Bureaucrat Program Error: " << e.what() << std::endl;
    }
    std::cout << "** Scope Destruction Highlighter... **\n";
}