#include "Bureaucrat.hpp"

//// constructors & destructors ////
Bureaucrat::Bureaucrat(){
    std::cout << "Burreaucrat Default Constructor Called..." << std::endl;
    Bureaucrat("BureauCratic", 11);
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName){
    std::cout << "Burreaucrat Name/Grade Constructor Called..." << std::endl;
    try {
        GradeTooHighException(newGrade);
        GradeTooLowException(newGrade);
        std::cout << "Grade Succesfully Given..." << std::endl;
    }
    catch (const std::invalid_argument& e) {
        
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

unsigned int Bureaucrat::getGrade()const{
    return (this->grade);
}

void Bureaucrat::setGrade(int grade){
    this->grade = grade;
}

//// Incre/Decrement ////
void Bureaucrat::gradeIncrement(int inc){
    this->grade -= inc;
}

void Bureaucrat::gradeDecrement(int dec){
    this->grade += dec;
}

//// Exception's Functions ////
void Bureaucrat::GradeTooHighException(int value){
    if (value < 1){
        throw std::invalid_argument(std::to_string(value) + " is too high to be given...");
    }
}

void Bureaucrat::GradeTooLowException(int value){
    if (value > 150){
        throw std::invalid_argument(std::to_string(value) + " is too low to be given...");
    }
}