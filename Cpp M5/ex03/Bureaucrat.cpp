#include "Bureaucrat.hpp"
#include "AForm.hpp"

//// constructors & destructors ////
Bureaucrat::Bureaucrat() : name("Bureaucratic"), grade(1) {
    std::cout << "Bureaucrat Default Constructor Called..." << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName) {
    std::cout << "Bureaucrat Name/Grade Constructor Called..." << std::endl;
    if (newGrade > 150) throw GradeTooLowException();
    else if (newGrade < 1) throw GradeTooHighException();
    std::cout << "Grade Succesfully Given..." << std::endl;
    this->grade = newGrade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor Called..." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << "Bureaucrat Copy Constructor Called..." << std::endl;
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

//// Form's Tools ////
void Bureaucrat::signForm(AForm &Aform) {
 
    try {
        Aform.beSigned(*this);
        std::cout << this->getName() << " signed " \
        << Aform.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << this->getName() << " couldn't sign " \
        << Aform.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " \
        << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << this->getName() << " couldn't execute " \
        << form.getName() << " because " << e.what() << std::endl;
    }
}