#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;
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

        // setters & getters //
        std::string getTarget() const;
        std::string getFromName() const;
        void setTarget(std::string _target_);
        void setFormName(std::string _formName_);

        // Tools //
        AForm *makeForm(std::string formName, std::string target);
};

#endif