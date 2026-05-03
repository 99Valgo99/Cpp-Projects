#ifndef INTERN_HPP
#define INTERN_IPP

#include <iostream>

class AForm;
class Bureaucrat;
class RobotomyRequestForm;
class ShrubberyCreationForm;
class PresidentialPardonForm;

class Intern
{
    private:
        std::string target;
        std::string formName;
    public:
        Intern();
        Intern(std::string _formName_, std::string _target_);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // Tools //
        AFom *makeFrom();
}

#endif