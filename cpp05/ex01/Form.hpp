#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
	const int	grade_to_sign;
	const int	grade_to_execute;
	bool		is_signed;
	const std::string name;
	public:
		Form();
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();

		Form(const std::string& name, int grade_to_sign, int grade_to_execute);
		const	std::string& getName( void ) const;
		bool	getIsSigned( void ) const;
		int		getGradeToSign( void ) const;
		int		getGradeToExecute( void ) const;
		void	beSigned(const Bureaucrat& Bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
