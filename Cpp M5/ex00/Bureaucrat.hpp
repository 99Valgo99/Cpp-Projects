#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        // constructors & destructor
        Bureaucrat();
        Bureaucrat(std::string newName, int newGrade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        // Getters
        std::string getName() const;
        unsigned int getGrade() const;
        // Setters
        void setGrade(int grade);
        // Incre/Decre
        void gradeIncrement(int inc);
        void gradeDecrement(int dec);

        // exception's functions
        void GradeTooHighException(int value);
        void GradeTooLowException(int value);
};

#endif