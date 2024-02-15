
#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &obj)
{
	*this = obj;
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
		std::cout << "Dog operator = " << type << " called\n";
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called\n";
}

void Dog::makeSound(void) const
{
	std::cout << "🐶 : mungmung\n";	
}