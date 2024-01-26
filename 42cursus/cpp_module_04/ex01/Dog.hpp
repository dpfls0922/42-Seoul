#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &dog);
        Dog& operator=(const Dog &dog);
        ~Dog();

        std::string getDogIdea(int index);
        void setDogIdea(int index, std::string str);
        void makeSound(void) const;
};

# endif