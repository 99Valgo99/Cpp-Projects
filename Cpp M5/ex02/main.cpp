# include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
data:
    * ShrubberyCreationForm: Sign: 145 | Exec: 137
    * RobotomyRequestForm: Sign: 72 | Exec: 45
    * PresidentialPardonForm: Sign: 25 | Exec: 5
*/

int main()
{
    Bureaucrat Buro("Buro", 1);
    PresidentialPardonForm PPF("Pardon");
    Buro.executeForm(PPF);
    Buro.signForm(PPF);
    std::cout << "**-------------------------**" << std::endl;
    Buro.executeForm(PPF);
    std::cout << "**-------------------------**" << std::endl;
    RobotomyRequestForm RRF("Robotomy");
    Buro.signForm(RRF);
    std::cout << "**-------------------------**" << std::endl;
    Buro.executeForm(RRF);
    std::cout << "**-------------------------**" << std::endl;
    ShrubberyCreationForm SCF("Shrubbery");
    Buro.signForm(SCF);
    std::cout << "**-------------------------**" << std::endl;
    Buro.executeForm(SCF);
}