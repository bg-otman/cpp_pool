#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Bureaucrat executor_high("The Boss", 4);
    Bureaucrat executor_mid("The Middle", 70);
    Bureaucrat signer_low("The Temp", 140);

    AForm *shrubbery = new ShrubberyCreationForm("Home");
    AForm *robotomy = new RobotomyRequestForm("Bender");
    AForm *pardon = new PresidentialPardonForm("Criminal");

    signer_low.signForm(*shrubbery);
    executor_high.executeForm(*shrubbery); // Should create Home_shrubbery file.

    executor_high.signForm(*robotomy);
    executor_high.executeForm(*robotomy); // Should print noise + success/failure.

    executor_high.signForm(*pardon);
    executor_high.executeForm(*pardon); // Should print pardon message.


    std::cout << "\n--- Execution Failure Tests ---" << std::endl;
    try {
        executor_mid.executeForm(*pardon); // Should catch GradeTooLowException internally.
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
    }

    AForm *unsigned_robotomy = new RobotomyRequestForm("UnsignedTarget");
    
    try {
        executor_high.executeForm(*unsigned_robotomy); // Should catch FormNotSignedException internally.
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
    }

    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete unsigned_robotomy;

    return 0;
}