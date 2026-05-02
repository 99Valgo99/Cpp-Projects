#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;
    public:
     // constructors & destructor //
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string _target_);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    
    // getter //
    std::string getTargetName();
    // form execution //
    void formExecution();
};

#endif