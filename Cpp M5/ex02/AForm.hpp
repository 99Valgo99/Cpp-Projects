#ifndef AFORM_HPP
#define AFORM_HPP

# include "Bureaucrat.hpp"

# define TRUE 1
# define FALSE 0

class AForm
{
    private:
        const std::string name;
        bool marked;
        const int gradeSign;
        const int gradeExec;
    public:
    // constructors & destructor //
    AForm();
    AForm(std::string newName, int newGradeSign, int newGradeExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
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
    // AForm Tools //
    void beSigned(const Bureaucrat &obj);
    
    // Execution Checker //
    void execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream &out, const AForm& input);

# endif