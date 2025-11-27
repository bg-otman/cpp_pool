#include "Form.hpp"

Form::Form()
	: grade_to_sign(150), grade_to_execute(150),
		is_signed(false), name("DefaultForm")
{
	// is_signed = false;
}

Form::Form(const Form& obj)
	: grade_to_sign(obj.grade_to_sign), grade_to_execute(obj.grade_to_execute),
		is_signed(obj.is_signed), name(obj.name)
{
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		is_signed = obj.is_signed;
	}
	return (*this);
}

Form::~Form()
{
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute)
	: grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute),
		is_signed(false), name(name)
{
	if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
		throw GradeTooHighException();
	else if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
		throw GradeTooLowException();
}

const std::string& Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return is_signed;
}

int Form::getGradeToSign() const
{
	return grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return grade_to_execute;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	std::cout << "Form name : " << obj.getName() << std::endl;
	std::cout << "is_signed : ";
	obj.getIsSigned() ? std::cout << "True" : std::cout << "False";
	std::cout << std::endl;
	std::cout << "Required Grade to sign : " << obj.getGradeToSign() << std::endl;
	std::cout << "Required Grade to excute : " << obj.getGradeToExecute() << std::endl;
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "An exception Occured : Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "An exception Occured : Grade Too Low";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}
