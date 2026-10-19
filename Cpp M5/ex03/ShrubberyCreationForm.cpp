#include <fstream>
#include "ShrubberyCreationForm.hpp"

// constructors & destructors //
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {
std::cout << "ShrubberyCreationForm Default Constructor Called..." << std::endl;
this->target = "RandomTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target_): AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "ShrubberyCreationForm Parametrized Constructor Called..." << std::endl;
    this->target = _target_;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target) {
    std::cout << "ShrubberyCreationForm Copy Constructor Called..." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm Assignenent Operator Called..." << std::endl;
    if (this != &other){
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

/// getter //
std::string ShrubberyCreationForm::getTargetName() const {
    return (this->target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor Called..." << std::endl;
}

/// Form Execution //
void ShrubberyCreationForm::formExecution() const {

    std::ofstream outfile((this->getTargetName() + "_shrubbery").c_str());
    if (!outfile) {
        std::cerr << "Error: Failed To Open The File..." << std::endl;
        return ;
    }
    outfile << "        *                 *        " << std::endl;
    outfile << "       /_\\               /_\\       " << std::endl;
    outfile << "      /_ _\\             /_ _\\      " << std::endl;
    outfile << "     /_ _ _\\           /_ _ _\\     " << std::endl;
    outfile << "    /_ _ _ _\\         /_ _ _ _\\    " << std::endl;
    outfile << "   /_ _ _ _ _\\       /_ _ _ _ _\\   " << std::endl;
    outfile << "  /_ _ _ _ _ _\\     /_ _ _ _ _ _\\  " << std::endl;
    outfile << "       |||               |||       " << std::endl;
    outfile << "       |||               |||       " << std::endl;
    outfile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    outfile.close();
    std::cout << "Ascii Trees Written To " << this->getTargetName() << "_shrubbery" << std::endl;
}