
#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = "nothing";
    }
    std::cout << "Brain default constructor called\n";
}

Brain::Brain(std::string idea)
{

    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = idea;
    }
    std::cout << "Brain constructor called\n";
}

Brain::Brain(Brain const &obj)
{
    *this = obj;
    std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(Brain const &obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = obj.getIdea(i);
        }
        std::cout << "Brain operator = called\n";
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called\n";
}

std::string Brain::getIdea(int index) const
{
    return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string str)
{
    this->ideas[index] = str;
}