
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &obj)
{
	*this = obj;
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
		std::cout << "WrongCat operator = " << type << " called\n";
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat class can not make sound\n";	
}
