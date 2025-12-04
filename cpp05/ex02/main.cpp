#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// int main()
// {
// 	// AForm* f = new ShrubberyCreationForm("home");
// 	// try
// 	// {
// 	// 	Bureaucrat trump("Trump", 0);
// 	// 	trump.signForm(*f);
// 	// trump.executeForm(*f);

// 	// }
// 	// catch(const std::exception& e)
// 	// {
// 	// 	std::cerr << e.what() << '\n';
// 	// }
	

// 	// AForm* r = new RobotomyRequestForm("Office");
// 	// try
// 	// {
// 	// 	Bureaucrat trump("Trump", 40);
// 	// 	trump.signForm(*r);
// 	// 	trump.executeForm(*r);
// 	// }
// 	// catch(const std::exception& e)
// 	// {
// 	// 	std::cerr << e.what() << '\n';
// 	// }
	
// 	return 0;
// }


int main() {
    Bureaucrat executor_high("The Boss", 4);
    Bureaucrat executor_mid("The Middle", 70);
    Bureaucrat signer_low("The Temp", 140);

    AForm *shrubbery = new ShrubberyCreationForm("Home");
    AForm *robotomy = new RobotomyRequestForm("Bender");
    AForm *pardon = new PresidentialPardonForm("Criminal");

    // --- A. Shrubbery Test (Low Grade) ---
    // Signer (140) signs the Shrubbery Form (req 145).
    signer_low.signForm(*shrubbery);
    // Executor (4) executes the Shrubbery Form (req 137).
    executor_high.executeForm(*shrubbery); // Should create Home_shrubbery file.

    // --- B. Robotomy Test (Mid Grade) ---
    // The Boss (4) signs the Robotomy Form (req 72).
    executor_high.signForm(*robotomy);
    // The Boss (4) executes the Robotomy Form (req 45). (50% success chance)
    executor_high.executeForm(*robotomy); // Should print noise + success/failure.

    // --- C. Pardon Test (High Grade) ---
    // The Boss (4) signs the Pardon Form (req 25).
    executor_high.signForm(*pardon);
    // The Boss (4) executes the Pardon Form (req 5).
    executor_high.executeForm(*pardon); // Should print pardon message.


    std::cout << "\n--- Execution Failure Tests ---" << std::endl;

    // --- D. Failure: Grade Too Low ---
    // The Boss (4) signs the Pardon Form (req 25) (already done, but re-confirm).
    // The Middle (70) attempts to execute the Pardon Form (req 5). 70 is too low.
    try {
        executor_mid.executeForm(*pardon); // Should catch GradeTooLowException internally.
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
    }

    // --- E. Failure: Not Signed ---
    // Create a new form that is not signed.
    AForm *unsigned_robotomy = new RobotomyRequestForm("UnsignedTarget");
    
    // Executor (4) attempts to execute the unsigned form.
    try {
        executor_high.executeForm(*unsigned_robotomy); // Should catch FormNotSignedException internally.
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
    }

    // Cleanup
    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete unsigned_robotomy;

    return 0;
}