
#include "Animal.hpp"

Animal::Animal()
{
	this->type = "animal";
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &obj)
{
	*this = obj;
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
		std::cout << "Animal operator = " << type << " called\n";
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called\n";
}

std::string Animal::getType(void) const
{
	return (this->type);
}
