# include "Form.hpp"

int main()
{
    Bureaucrat ableBuro("AbleBuro", 1);
    Bureaucrat unableBuro("UnableBuro", 11);
    std::cout << ableBuro << std::endl;
    std::cout << unableBuro << std::endl;
    std::cout << "***-----------------------***\n";

    Form Form("Form1", 2, 11);
    std::cout << Form << std::endl;
    std::cout << "\n***----- Successfull Form Signing ----***\n\n";
    ableBuro.signForm(Form);

    std::cout << "***----- Unsuccessfull Form Signing ----***\n\n";
    unableBuro.signForm(Form);
}