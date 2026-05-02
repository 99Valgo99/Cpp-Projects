#include "PresidentialPardonForm.hpp"

// constructors & destructors //
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {
std::cout << "PresidentialPardonForm Default Constructor Called..." << std::endl;
this->target = "RandomTarget";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target_): AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "PresidentialPardonForm Parametrized Constructor Called..." << std::endl;
    this->target = _target_;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target) {
    std::cout << "PresidentialPardonForm Copy Constructor Called..." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm Assignenent Operator Called..." << std::endl;
    if (this != &other){
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor Called..." << std::endl;
}

/// getter //
std::string PresidentialPardonForm::getTargetName() {
    return (this->target);
}

/// form execution //
void PresidentialPardonForm::formExecution(){
    std::cout << this->getTargetName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}