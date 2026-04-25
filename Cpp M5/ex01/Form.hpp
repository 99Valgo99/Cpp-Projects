#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool marked;
        const int gradeSign;
        const int gradeExec;
    public:
    // constructors & destructor //
    Form();
    Form(std::string newName, int newGradeSign, int newGradeExec, bool isMarked);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    // getters //
    bool getMarked() const;
    int getGradeSign() const;
    int getGradeExec() const;
    std::string getName() const;
    
    // exception's classes //
    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };
    
    // Form Tools //
    void beSigned(const Bureaucrat &obj);
};

std::ostream& operator<<(std::ostream &out, const Form& input);

# endif;