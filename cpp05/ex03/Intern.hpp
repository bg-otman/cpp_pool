#ifndef INTERN_HPP
#define INTERN_HPP

// #include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
    private:

    public:
        Intern();
        Intern(const Intern& obj);
        Intern& operator=(const Intern& obj);
        ~Intern();

        AForm* makeForm(const std::string& form_name, const std::string& form_target) const;
};

#endif
