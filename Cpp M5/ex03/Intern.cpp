#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//// constructors & destructor ////
Intern::Intern() {
    std::cout << "Intern Default Constructor Called..." << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern Copy Constructor Called..." << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern Assignement Operator Called..." << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern Destructor Called..." << std::endl;
}

//// form creators ////
AForm* Intern::createPresidential(const std::string& target) const {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomy(const std::string& target) const {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubbery(const std::string& target) const {
    return (new ShrubberyCreationForm(target));
}

//// nake form ////
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const std::string names[3] = {
        "presidential pardon", "robotomy request", "shrubbery creation"
    };
    AForm* (Intern::*creators[3])(const std::string&) const = {
        &Intern::createPresidential,
        &Intern::createRobotomy,
        &Intern::createShrubbery
    };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*creators[i])(target));
        }
    }
    std::cerr << "Error: Could not find the form \"" << formName << "\"..." << std::endl;
    std::cerr << "Current Options: presidential pardon | robotomy request | shrubbery creation" << std::endl;
    return (NULL);
}