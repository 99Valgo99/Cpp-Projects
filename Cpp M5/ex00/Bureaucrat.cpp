#include "Bureaucrat.hpp"

//// constructors & destructors ////
Bureaucrat::Bureaucrat() : name("Bureaucratic"), grade(1) {
    std::cout << "Burreaucrat Default Constructor Called..." << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName) {
    std::cout << "Burreaucrat Name/Grade Constructor Called..." << std::endl;
    if (newGrade > 150) throw GradeTooLowException();
    else if (newGrade < 1) throw GradeTooHighException();
    std::cout << "Grade Succesfully Given..." << std::endl;
    this->grade = newGrade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Burreaucrat Destructor Called..." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << "Burreaucrat Copy Constructor Called..." << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat Assignement Operator Called..." << std::endl;
    if (this != &other)
        this->grade = other.getGrade();
    return *this;
}

///// getters //////
std::string Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade()const {
    return (this->grade);
}

//// Incre/Decrement ////
void Bureaucrat::gradeIncrement() {
    if (this->grade - 1 < 1) throw GradeTooHighException();
    std::cout << "Grade Successfully Incremented..." << std::endl;
    this->grade -= 1;
}

void Bureaucrat::gradeDecrement() {
    if (this->grade + 1 > 150) throw GradeTooLowException();
    std::cout << "Grade Successfully Decremented..." << std::endl;
    this->grade += 1;
}

//// Exception's Functions ////
const char* Bureaucrat::GradeTooHighException:: what() const throw() {
    return ("Grade is too high to be set...");
}

const char* Bureaucrat::GradeTooLowException:: what() const throw() {
    return ("Grade is too low to be set...");
}

//// insertion operator ////
std::ostream& operator<<(std::ostream &out, const Bureaucrat& input) {
    out << input.getName() << ", bureaucrat grade " << input.getGrade() << ".";
    return (out);
}