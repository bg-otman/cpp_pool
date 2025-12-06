#include "AForm.hpp"

AForm::AForm()
	: grade_to_sign(150), grade_to_execute(150),
		is_signed(false), name("DefaultAForm")
{
}

AForm::AForm(const AForm& obj)
	: grade_to_sign(obj.grade_to_sign), grade_to_execute(obj.grade_to_execute),
		is_signed(obj.is_signed), name(obj.name)
{
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
	{
		is_signed = obj.is_signed;
	}
	return (*this);
}

AForm::~AForm()
{
}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute)
	: grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute),
		is_signed(false), name(name)
{
	if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
		throw GradeTooHighException();
	else if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
		throw GradeTooLowException();
}

const std::string& AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return is_signed;
}

int AForm::getGradeToSign() const
{
	return grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return grade_to_execute;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	std::cout << "AForm name : " << obj.getName() << std::endl;
	std::cout << "is_signed : ";
	obj.getIsSigned() ? std::cout << "True" : std::cout << "False";
	std::cout << std::endl;
	std::cout << "Required Grade to sign : " << obj.getGradeToSign() << std::endl;
	std::cout << "Required Grade to excute : " << obj.getGradeToExecute() << std::endl;
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "An exception Occured : Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "An exception Occured : Grade Too Low";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "An exception Occured : Form Not Signed";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!is_signed)
		throw FormNotSigned();
	else if (executor.getGrade() > grade_to_execute)
		throw GradeTooLowException();
	else
		this->executeAction();
}
