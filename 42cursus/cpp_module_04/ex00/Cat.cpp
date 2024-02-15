
#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &obj)
{
	*this = obj;
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
		std::cout << "Cat operator = " << type << " called\n";
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called\n";
}

void Cat::makeSound(void) const
{
	std::cout << "🐱 : Nyaaaong\n";	
}