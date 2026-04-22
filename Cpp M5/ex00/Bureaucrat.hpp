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
        // constructors & destructor //
        Bureaucrat();
        Bureaucrat(std::string newName, int newGrade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        // setters
        std::string getName() const;
        unsigned int getGrade() const;
        // setters //
        void setGrade(int grade);
        // sncre/secre //
        void gradeIncrement(int inc);
        void gradeDecrement(int dec);

        // exception's classes //
        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &out, const Fixed& input);

#endif