#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm("RobotomyRequestForm", 72, 45), target(obj.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Vnnnnnnnnnnnn (drilling noises)" << std::endl;
	
	srand(time(0));
	int is_robotomized = rand() % 2;

	if (is_robotomized)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy failed to robotized " << target << std::endl;
}

AForm*	RobotomyRequestForm::createRobotForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}
