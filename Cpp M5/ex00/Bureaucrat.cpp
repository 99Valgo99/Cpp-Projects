#include "Bureaucrat.hpp"

//// constructors & destructors ////
Bureaucrat::Bureaucrat() : name("Bureaucratic"), grade(11) {
    std::cout << "Burreaucrat Default Constructor Called..." << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName){
    std::cout << "Burreaucrat Name/Grade Constructor Called..." << std::endl;
    try {
        if (newGrade > 150)
            throw GradeTooLowException();
        else (newGrade < 1)
            throw GradeTooLowException();
        std::cout << "Grade Succesfully Given..." << std::endl;
    }
    this->grade = newGrade;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Burreaucrat Destructor Called..." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    std::cout << "Burreaucrat Copy Constructor Called..." << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    std::cout << "Bureaucrat Assignement Operator Called..." << std::endl;
    if (this != &other)
        this->setGrade(other.getGrade());
    return *this;
}

///// getters //////
std::string Bureaucrat::getName() const{
    return (this->name);
}

int Bureaucrat::getGrade()const{
    return (this->grade);
}

void Bureaucrat::setGrade(int grade){
    this->grade = grade;
}

//// Incre/Decrement ////
void Bureaucrat::gradeIncrement(){
    this->grade -= 1;
}

void Bureaucrat::gradeDecrement(){
    this->grade += 1;
}

//// Exception's Functions ////
const char* Bureaucrat::GradeTooHighException:: what() const throw() {
    return ("Grade is too high to be set...");
}

const char* Bureaucrat::GradeTooLowException:: what() const throw() {
    return ("Grade is too low to be set...");
}