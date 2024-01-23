
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "default";
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
    this->name = obj.getName();
    this->hitPoint = obj.getAttackDamage();
    this->energyPoint = obj.getHitPoint();
    this->attackDamage = obj.getAttackDamage();
    std::cout << "ScavTrap " << this->name << " copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if (this != &obj)
    {
        this->name = obj.getName();
        this->hitPoint = obj.getHitPoint();
        this->energyPoint = obj.getEnergyPoint();
        this->attackDamage = obj.getAttackDamage();
        std::cout << "ScavTrap operator = " << name << " called\n";
    }
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->name << " destructor called\n";
}

void ScavTrap::guardGate(void)
{
    if (!this->hitPoint || !this->energyPoint)
    {
        std::cout << "ScavTrap " << this->name << " can not move\n";
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode\n";
    }
}

void ScavTrap::attack(std::string const& target)
{
    if (!this->hitPoint || !this->energyPoint)
    {
        std::cout << "ScavTrap " << this->name << " can not move\n";
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target;
        std::cout << ", causing " << this->attackDamage << " points of damage!\n";
        this->energyPoint--;
    }
}
