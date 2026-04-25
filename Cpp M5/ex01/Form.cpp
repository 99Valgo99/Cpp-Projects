# include "Form.hpp"

// constructors & destructors //
Form::Form() : name("Form"), marked(false), gradeSign(1), gradeExec(1) {
    std::cout << "Form Default Constructor Called..." << std::endl;
}

Form::Form(std::string newName, int newGradeSign, int newGradeExec, bool isMarked) :\
 name(newName), marked(isMarked),\
  gradeSign(newGradeSign), gradeExec(newGradeExec) {
    
    std::cout << "Parametrized Form Constructor Is Called..." << std::endl;
    if (newGradeExec > 150 || newGradeSign > 150) throw GradeTooLowException();
    else if (newGradeExec < 1 || newGradeSign < 1) throw GradeTooHighException();
    std::cout << "Form's Grades Succesfully Given..." << std::endl;
}

Form::~Form(){
    std::cout << "Form Destructor Called..." << std::endl;
}

Form::Form(const Form& other) : \
name(other.name), marked(other.marked), \
gradeSign(other.gradeSign), gradeExec(other.gradeExec) {

    std::cout << "Form Copy Constructor Called..." << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form Assignment Operator Called..." << std::endl;
    if (this != &other)
        this->marked = other.getMarked();
    return *this;
}

// Getters