#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string name;
        unsigned int grade;
    public:
        // constructors & destructor
        Bureaucrat();
        Bureaucrat(std::string newName, unsigned int newGrade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        // Getters
        std::string getName() const;
        unsigned int getGrade() const;
        // Setters
        void setGrade(unsigned int grade);
        // exception's functions

};

#endif