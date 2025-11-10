#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		const std::string& getName( void ) const;
		int	getGrade( void ) const;
		void incrementGrade( void );
		void decrementGrade( void );

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();// overrride (what) func in exception class
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
