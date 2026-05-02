#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
    // constructors & destructor //
    RobotomyRequestForm();
    RobotomyRequestForm(std::string _target_);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    // getter //
    std::string getTargetName();
    // form execution //
    void formExecution();
};


#endif