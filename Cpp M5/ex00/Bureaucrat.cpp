#include "Bureaucrat.hpp"

// constructors & destructors
Bureaucrat::Bureaucrat(){
    std::cout << "Burreaucrat Default Constructor Called..." << std::endl;
    Bureaucrat("BureauCratic", 11);
}

Bureaucrat::Bureaucrat(std::string newName, unsigned int newGrade) : name(newName){
    std::cout << "Burreaucrat Name/Grade Constructor Called..." << std::endl;
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

void Bureaucrat::setGrade(unsigned int grade){
    this->grade = grade;
}
