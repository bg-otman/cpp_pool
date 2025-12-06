#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& obj)
{
    (void) obj;
}

Intern& Intern::operator=(const Intern& obj)
{
    (void) obj;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& form_name, const std::string& form_target) const
{
    std::string known_forms[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    AForm* (*ptr[]) (const std::string&)
        = { &RobotomyRequestForm::createRobotForm,
            &ShrubberyCreationForm::createShrubberyForm,
            &PresidentialPardonForm::createPresidentForm
          };
    AForm* newForm = NULL;
    for (size_t i = 0; i < 3; i++)
    {
        if (form_name == known_forms[i])
            newForm = ptr[i](form_target);
    }
    if (newForm)
        std::cout << "Intern creates " << form_name << std::endl;
    else
        std::cerr << "Invalid Form" << std::endl;
    return newForm;
}
