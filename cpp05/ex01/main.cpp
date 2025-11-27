#include "Form.hpp"

int main()
{
    Bureaucrat high_grade("Supervisor", 10);
    Bureaucrat low_grade("Intern", 140);
    Bureaucrat just_right("MidLevel", 50);

    Form easy_form("Easy_form", 100, 100);
    Form hard_form("Hard_form", 45, 1);
    
    std::cout << high_grade << std::endl;
    std::cout << low_grade << std::endl;

    std::cout << easy_form << std::endl;
    std::cout << hard_form << std::endl;

    std::cout << "#### Sign in Forms ####" << std::endl;

    try {
        high_grade.signForm(easy_form);
        std::cout << "-> Status: \n" << easy_form << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
	
	std::cout << "######################" << std::endl;

    try {
        low_grade.signForm(hard_form); // Should print failure message
        std::cout << "-> Status: \n" << hard_form << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Unexpected exception from signForm: " << e.what() << std::endl;
    }

	std::cout << "######################" << std::endl;

    try {
        // invalid sign grade
        Form invalid_form("Invalid", 0, 100);
    } catch (Form::GradeTooHighException& e) {
        std::cout << "Error in Form Construction: " << e.what() << std::endl;
    } catch (Form::GradeTooLowException& e) {
        std::cerr << "Error in Form Construction: " << e.what() << std::endl;
    }
	
	return 0;
}
