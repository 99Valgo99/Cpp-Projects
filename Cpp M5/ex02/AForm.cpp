# include "AForm.hpp"

// constructors & destructors //
AForm::AForm() : name("AFor"), marked(FALSE), gradeSign(1), gradeExec(1) {
    std::cout << "AForm Default Constructor Called..." << std::endl;
}

AForm::AForm(std::string newName, int newGradeSign, int newGradeExec) : name(newName), \
marked(FALSE), gradeSign(newGradeSign), gradeExec(newGradeExec) {
    
    std::cout << "Parametrized AForm Constructor Is Called..." << std::endl;
    if (newGradeExec > 150 || newGradeSign > 150) throw GradeTooLowException();
    else if (newGradeExec < 1 || newGradeSign < 1) throw GradeTooHighException();
    std::cout << "AForm's Grades Succesfully Given..." << std::endl;
}

AForm::~AForm(){
    std::cout << "AForm Destructor Called..." << std::endl;
}

AForm::AForm(const AForm& other) : \
name(other.name), marked(other.marked), \
gradeSign(other.gradeSign), gradeExec(other.gradeExec) {

    std::cout << "AForm Copy Constructor Called..." << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm Assignment Operator Called..." << std::endl;
    if (this != &other)
        this->marked = other.getMarked();
    return *this;
}

// getters
bool AForm::getMarked() const {
    return (marked);
}

int AForm::getGradeSign() const {
    return (gradeSign);
}

int AForm::getGradeExec() const {
    return (gradeExec);
}

std::string AForm::getName() const {
    return (name);
}

// AForm's exception's tools //
const char* AForm::GradeTooHighException:: what() const throw() {
    return ("AForm's Grade Is Too High...");
}

const char* AForm::GradeTooLowException:: what() const throw() {
    return ("AForm's Grade Is Too Low...");
}

const char* AForm::UnsignedForm:: what() const throw() {
    return ("AForm is not signed yet...");
}

// AForm tools //
void AForm::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() <= gradeSign) marked = TRUE;
    else if (obj.getGrade() > gradeSign) throw GradeTooLowException();
}

//// insertion operator ////
std::ostream& operator<<(std::ostream &out, const AForm& input) {
    
    out << "AForm Name: " << input.getName() << ", Marked As " \
    << std::boolalpha << input.getMarked() << ", Its Grade To Sign: " \
    << input.getGradeSign() << ", Its Grade To Execute: " << input.getGradeExec();
    return (out);
}

//// Execution Checker ////
void AForm::execute(Bureaucrat const & executor) const {
    std::cout << "Form Verification Ongoing..." << std::endl;
    if (!this->getMarked())
        throw UnsignedForm();
    std::cout << "Form is Signed..." << std::endl;
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    std::cout << "Form Can Be Executed..." << std::endl;
    this->formExecution();
}