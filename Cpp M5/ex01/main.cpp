# include "Form.hpp"

int main()
{
    Bureaucrat ableBuro("AbleBuro", 1);
    Bureaucrat unableBuro("UnableBuro", 11);
    std::cout << ableBuro << std::endl;
    std::cout << unableBuro << std::endl;
    std::cout << "***-----------------------***\n";

    Form Form1("Form1", 2, 11);
    std::cout << Form1 << std::endl;
    std::cout << "\n***----- Successfull Form Signing ----***\n\n";
    ableBuro.signForm(Form1);

    std::cout << "***----- Unsuccessfull Form Signing ----***\n\n";
    unableBuro.signForm(Form1);
    
    try {
        std::cout << "** Throw on construction **\n";
        Form Form2("Form2", 0, 11);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "test\n";
}