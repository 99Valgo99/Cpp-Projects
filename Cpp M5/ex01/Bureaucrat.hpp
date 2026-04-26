#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;
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
        // getters
        std::string getName() const;
        int getGrade() const;
        // incre/decre //
        void gradeIncrement();
        void gradeDecrement();

        // exception's classes //
        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            virtual const char* what() const throw();
        };
        // Form Tools //
        void signForm(Form &form);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& input);

#endif