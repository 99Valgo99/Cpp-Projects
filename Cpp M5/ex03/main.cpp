#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern internN01;

    AForm* PPF = internN01.makeForm("presidential pardon", "Boss");
    if (PPF)
        delete PPF;
    std::cout << "**---------------------**" << std::endl;
    
    AForm* RRF = internN01.makeForm("robotomy request", "robot");
    if (RRF)
        delete RRF;
    std::cout << "**---------------------**" << std::endl;

    AForm* SCF = internN01.makeForm("shrubbery creation", "Tree");
    if (SCF) {
        Bureaucrat Buro("Buro", 1);
        Buro.signForm(*SCF);
        Buro.executeForm(*SCF);
        delete SCF;
    }
}