#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
	: name("Bureaucrat"), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
	: name(obj.name), grade(obj.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		grade = obj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

const std::string& Bureaucrat::getName( void ) const
{
	return name;
}

int	Bureaucrat::getGrade( void ) const
{
	return grade;
}

void Bureaucrat::incrementGrade( void )
{
	if ((grade - 1) < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade( void )
{
	if ((grade + 1) > 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "An exception Occured : Grade Too High";
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "An exception Occured : Grade Too Low";
}

void Bureaucrat::signForm( AForm& form ) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because it's grade too low" << std::endl;
	}
	catch (const  AForm::GradeTooHighException& e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because it's grade too High" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
