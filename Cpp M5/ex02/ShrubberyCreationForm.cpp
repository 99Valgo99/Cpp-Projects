#include <fstream>
#include "ShrubberyCreationForm.hpp"

// constructors & destructors //
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 25, 5) {
std::cout << "ShrubberyCreationForm Default Constructor Called..." << std::endl;
this->target = "RandomTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target_): AForm("ShrubberyCreationForm", 25, 5) {
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
std::string ShrubberyCreationForm::getTargetName() {
    return (this->target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor Called..." << std::endl;
}

/// Form Execution //
void ShrubberyCreationForm::formExecution() {
    std::ofstream outfile;

    outfile.open(this->getTargetName().append("_shrubbery").c_str(), std::ios::out);
    if (!outfile) {
        std::cerr << "Error: Failed To Open The File." << std::endl;
        return ;
    }
    outfile << "BureaucraticAsciiTree" << std::endl;
    outfile << "---------------------" << std::endl;
    outfile << "\nCompany/" << std::endl;
    outfile << "├─ Bureaucratic Forms/" << std::endl;
    outfile << "│  ├─ IDs" << std::endl;
    outfile << "│  ├─ Dimplomas" << std::endl;
    outfile << "├─ Dates/" << std::endl;
    outfile << "│  ├─ Business Meetings" << std::endl;
    outfile << "│  ├─ Interviews" << std::endl;
    outfile << "├─ Private" << std::endl;
    outfile << "├─ ManagerOnly" << std::endl;
    outfile << "├─ EncryptedBackup" << std::endl;
    outfile << "|\n|--- Empoloyees/" << std::endl;
    outfile << "|    |-- Data" << std::endl;
    outfile << "|    |-- IDs" << std::endl;
    outfile << "|    |-- Certifications/" << std::endl;
    outfile << "|       |- Birth" << std::endl;
    outfile << "|       |- Assurance" << std::endl;
    outfile << "|       |- Contracts" << std::endl;
    outfile.close();
    std::cout << "Ascii Tree Written Successfully..." << std::endl;
}