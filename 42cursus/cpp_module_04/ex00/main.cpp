
#include "Polymorphism.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	const WrongCat wrongCat;

	std::cout << "getType : " << j->getType() << std::endl;
	j->makeSound();
	std::cout << "getType : " << i->getType() << std::endl;
	i->makeSound();
	std::cout << "getType : " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << "getType : " << wrong->getType() << std::endl;
	wrong->makeSound();
	wrongCat.makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong;
	return 0;
}