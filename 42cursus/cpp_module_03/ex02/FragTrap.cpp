
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "default";
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " constructor called\n";
}

FragTrap::FragTrap(const FragTrap& obj)
{
	this->name = obj.getName();
    this->hitPoint = obj.getHitPoint();
    this->energyPoint = obj.getEnergyPoint();
    this->attackDamage = obj.getAttackDamage();
    std::cout << "FragTrap " << this->name << " copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    if (this != &obj)
    {
        this->name = obj.getName();
        this->hitPoint = obj.getHitPoint();
        this->energyPoint = obj.getEnergyPoint();
        this->attackDamage = obj.getAttackDamage();
        std::cout << "FragTrap operator = " << this->name << " called\n";
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
    if (!this->hitPoint)
    {
        std::cout << "FragTrap " << this->name << " can not move\n";
    }
    else
    {
        std::cout << "FragTrap " << this->name << " high five!\n";
    }
}