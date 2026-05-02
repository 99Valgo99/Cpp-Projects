#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;
    public:
        // constructors & destructor //
        PresidentialPardonForm();
        PresidentialPardonForm(std::string _target_);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        // getter //
        std::string getTargetName();
        // form execution //
        void formExecution();
};

#endif