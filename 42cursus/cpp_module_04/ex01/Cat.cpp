
#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &obj)
{
	this->brain = new Brain();
	*this = obj;
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
		if (this->brain)
		{
			delete this->brain;
		}
		this->brain = new Brain(*obj.brain);
		std::cout << "Cat operator = " << type << " called\n";
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat Destructor called\n";
}

std::string Cat::getCatIdea(int index)
{	
	if (index >= 100)
	{
		std::cout << "Error: Out of range\n";
		return "";
	}
	return this->brain->getIdea(index);
}

void Cat::setCatIdea(int index, std::string str)
{
	if (index >= 100)
	{
		std::cout << "Error: Out of range\n";
		return ;
	}
	this->brain->setIdea(index, str);
}

void Cat::makeSound(void) const
{
	std::cout << "🐱 : Nyaaaong\n";	
}