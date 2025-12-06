#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class AForm
{
	private:
		const int	grade_to_sign;
		const int	grade_to_execute;
		bool		is_signed;
		const std::string name;
	public:
		AForm();
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();

		AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
		const	std::string& getName( void ) const;
		bool	getIsSigned( void ) const;
		int		getGradeToSign( void ) const;
		int		getGradeToExecute( void ) const;
		void	beSigned(const Bureaucrat& Bureaucrat);
		void	execute(Bureaucrat const & executor) const;
		virtual void executeAction( void ) const = 0;

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
		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
