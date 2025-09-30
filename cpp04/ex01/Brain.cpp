#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
    std::cout << "Brain Copy Constructor Called" << std::endl;
    *this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
    std::cout << "Brain Copy Assingement Operator Called" << std::endl;
    if (this != &obj)
    {
        for (size_t i = 0; i < 100; i++)
		{
			this->ideas[i] = obj.ideas[i];
		}
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}
