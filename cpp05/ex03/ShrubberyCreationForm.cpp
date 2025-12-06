#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: AForm("ShrubberyCreationForm", 145, 137), target(obj.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::string file_name = target + "_shrubbery";
	std::ofstream out_file(file_name.c_str());

	if (out_file.is_open())
	{
		out_file << 
			"              # #### ####\n"
			"            ### \\/#|### |/####\n"
			"           ##\\/#/ \\||/##/_/##/_#\n"
			"         ###  \\/###|/ \\/ # ###\n"
			"       ##_\\_#\\_\\## | #/###_/_####\n"
			"      ## #### # \\ #| /  #### ##/##\n"
			"       __#_--###`  |{,###---###-~\n"
			"                 \\ }{\n"
			"                  }}{\n"
			"                  }}{\n"
			"                  {{}\n";
	}
	else
		std::cerr << "Error in opening file" << std::endl;
}

AForm*	ShrubberyCreationForm::createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}
