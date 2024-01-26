
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &obj)
{
	this->brain = new Brain();
	*this = obj;
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
		if (this->brain)
		{
			delete this->brain;
		}
		this->brain = new Brain(*obj.brain);
		std::cout << "Dog operator = " << type << " called\n";
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog Destructor called\n";
}

std::string Dog::getDogIdea(int index)
{	
	if (index >= 100)
	{
		std::cout << "Error: Out of range\n";
		return "";
	}
	return this->brain->getIdea(index);
}

void Dog::setDogIdea(int index, std::string str)
{
	if (index >= 100)
	{
		std::cout << "Error: Out of range\n";
		return ;
	}
	this->brain->setIdea(index, str);
}

void Dog::makeSound(void) const
{
	std::cout << "🐶 : mungmung\n";	
}