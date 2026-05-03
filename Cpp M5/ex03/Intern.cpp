#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

//// constructors & destructor ////
Intern::Intern() {
    std::cout << "Intern Default Constructor Called..." << std::endl;
    this->target = "Random";
    this->formName = "robotomy request";
}

Intern::Intern(std::string _formName_, std::string _target_) {
    std::cout << "Intern Parametrized Constructor Called..." << std::endl;
    this->target = _target_;
    this->formName = _formName_;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern Copy Constructor Called..." << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern Assignement Operator Called..." << std::endl;
    if (this != &other) {
        this->setTarget(other.getTarget());
        this->setFormName(other.getFromName());
    }
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern Destructor Called..." << std::endl;
}

//// setters & getters ////
std::string Intern::getTarget() const {
    return (this->target);
}
std::string Intern::getFromName() const {
    return (this->formName);
}
void Intern::setTarget(std::string _target_) {
    this->target = _target_;
}
void Intern::setFormName(std::string _formName_) {
    this->target = _formName_;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string Forms[4] = {
        "presidential pardon", "robotomy request", 
        "shrubbery creation", "not found"
    };
    int search = 0;
    while (search < 3) {
        if (!Forms[search].compare(formName))
            break ;
        search++;
    }
    if (search == 3) {
        std::cerr << "Error: Could not found the matched form..." << std::endl;
        std::cerr << "Current Options: presidential pardon | robotomy request | shrubbery creation" << std::endl;
        return (NULL);
    }
    switch (search) {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return (new PresidentialPardonForm(target));
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return (new ShrubberyCreationForm(target));
        default:
            std::cerr << "Unexpected Behavior Occured..." << std::endl;
    }
    return (NULL);
}