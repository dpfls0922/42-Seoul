
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	*this = obj;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
		std::cout << "WrongAnimal operator = " << type << " called\n";
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called\n";
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal class can not make sound\n";	
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}