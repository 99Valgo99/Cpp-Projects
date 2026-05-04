#include "RobotomyRequestForm.hpp"

// constructors & destructors //
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 25, 5) {
std::cout << "RobotomyRequestForm Default Constructor Called..." << std::endl;
this->target = "RandomTarget";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target_): AForm("RobotomyRequestForm", 25, 5) {
    std::cout << "RobotomyRequestForm Parametrized Constructor Called..." << std::endl;
    this->target = _target_;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target) {
    std::cout << "RobotomyRequestForm Copy Constructor Called..." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm Assignenent Operator Called..." << std::endl;
    if (this != &other){
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

/// getter //
std::string RobotomyRequestForm::getTargetName() const {
    return (this->target);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor Called..." << std::endl;
}

/// Form Execution //
void RobotomyRequestForm::formExecution() const {
    std::cout << "Machine Started..VVV...DSDS.." << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << this->getTargetName() << " has been robotomized." << std::endl;
    else
        std::cout << this->getTargetName() << " has not been robotomized" << std::endl;
}