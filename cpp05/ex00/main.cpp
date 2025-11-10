#include "Bureaucrat.hpp"

int main()
{
    // --- Successful Bureaucrat ---
	try
	{
		Bureaucrat trump("trump", 1);
		std::cout << trump << std::endl;
		trump.decrementGrade();
		std::cout << "after decrement : " << trump << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;



    // --- Too High Bureaucrat ---
	try
	{
		Bureaucrat trump("trump", 0);
		std::cout << trump << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;




    // --- Too Low Bureaucrat ---
	try
	{
		Bureaucrat trump("trump", 151);
		std::cout << trump << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------" << std::endl;




    // --- Increment Cause Exception ---
	try
	{
		Bureaucrat trump("trump", 1);
		std::cout << trump << std::endl;
		trump.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "after incrementing : " << e.what() << std::endl;
	}

	
	return 0;
}
