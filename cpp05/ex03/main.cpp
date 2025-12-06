#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form_ptr = NULL;

    form_ptr = someRandomIntern.makeForm("shrubbery creation", "Bender");
    try
    {
        Bureaucrat trump("trump", 2);
        trump.signForm(*form_ptr);
        trump.executeForm(*form_ptr);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete form_ptr;
    
    form_ptr = someRandomIntern.makeForm("robotomy request", "Criminal");
    delete form_ptr;

    form_ptr = someRandomIntern.makeForm("HAHAHA", "HOHOHO");

    return 0;
}
