
#include "Polymorphism.hpp"

void	system_check(void)
{
	system("leaks a.out");
}

int main()
{
	atexit(system_check);

	Animal  *meta[4];
	for(int i = 0; i < 4; i++)
	{
		if (i < 2)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	for(int i = 0; i < 4; i++)
		meta[i]->makeSound();
	for(int i = 0; i < 4; i++)
		delete meta[i];
	
	std::cout << "=================================\n";
	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog();
	std::cout << std::endl;

	std::cout << "Dog1's first idea is "<< dog1->getDogIdea(0) << std::endl;

	dog1->setDogIdea(0, "something");
	std::cout << "Dog1's first idea is "<< dog1->getDogIdea(0) << std::endl;

	*dog2 = *dog1;
	std::cout << "Dog2's first idea is "<< dog2->getDogIdea(0) << std::endl;

	std::cout << std::endl;
	delete dog1;
	dog1 = NULL;
	delete dog2;
	dog2 = NULL;

	return 0;
}