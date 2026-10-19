#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern
{
    private:
        AForm* createPresidential(const std::string& target) const;
        AForm* createRobotomy(const std::string& target) const;
        AForm* createShrubbery(const std::string& target) const;
    public:
        // constructors & destructor //
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // tools //
        AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif