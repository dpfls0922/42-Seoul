# C++ - Module 04

## Exercise 00: Polymorphism

```
Exercise : 00
Polymorphism
Turn-in directory : ex00/
Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions : None
```

For every exercise, you have to provide **the most complete tests** you can.
Constructors and destructors of each class must display specific messages. Don’t use the
same message for all classes.
Start by implementing a simple base class called **Animal**. It has one protected
attribute:

- `std::string type;`
Implement a **Dog** class that inherits from Animal.
Implement a **Cat** class that inherits from Animal.
- These two derived classes must set their type field depending on their name. Then,
the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
The type of the Animal class can be left empty or set to the value of your choice.
- Every animal must be able to use the member function: `makeSound()`
It will print an appropriate sound (cats don’t bark).

Running this code should print the specific sounds of the Dog and Cat classes, not
the Animal’s.

```cpp
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	...
	return 0;
}
```

To ensure you understood how it works, implement a **WrongCat** class that inherits
from a **WrongAnimal** class. If you replace the Animal and the Cat by the wrong ones
in the code above, the WrongCat should output the WrongAnimal sound.
Implement and turn in more tests than the ones given above.

## Exercise 01: I don’t want to set the world on fire

```
Exercise : 01
I don’t want to set the world on fire
Turn-in directory : ex01/
Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}
Forbidden functions : None
```

Constructors and destructors of each class must display specific messages.

Implement a **Brain** class. It contains an array of 100 std::string called ideas.
This way, Dog and Cat will have a private Brain* attribute.
Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain.

In your main function, create and fill an array of **Animal** objects. Half of it will be **Dog** objects and the other half will be **Cat** objects. At the end of your program execution, loop over this array and delete every Animal. You must delete directly dogs and cats as Animals. The appropriate destructors must be called in the expected order.

Don’t forget to check for **memory leaks.**

A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies
are deep copies!

```cpp
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	...
	return 0;
}
```

Implement and turn in more tests than the ones given above.

## Exercise 02: Abstract class

```
Exercise : 02
Abstract class
Turn-in directory : ex02/
Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}
Forbidden functions : None

```

Creating Animal objects doesn’t make sense after all. It’s true, they make no sound!

To avoid any possible mistakes, the default Animal class should not be instantiable.
Fix the Animal class so nobody can instantiate it. Everything should work as before.

If you want to, you can update the class name by adding a A prefix to Animal.