
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "default";
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << this->name << " constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    this->name = obj.getName();
    this->hitPoint = obj.getHitPoint();
    this->energyPoint = obj.getEnergyPoint();
    this->attackDamage = obj.getAttackDamage();
    std::cout << "ClapTrap " << this->name << " copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    if (this != &obj)
    {
        this->name = obj.getName();
        this->hitPoint = obj.getHitPoint();
        this->energyPoint = obj.getEnergyPoint();
        this->attackDamage = obj.getAttackDamage();
        std::cout << "ClapTrap operator = " << name << " called\n";
    }
	return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (!this->hitPoint || !this->energyPoint)
    {
        std::cout << "ClapTrap " << this->name << " can not move\n";
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target;
        std::cout << ", causing " << this->attackDamage << " points of damage!\n";
        this->energyPoint--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoint == 0)
    {
        std::cout << "ClapTrap " << this->name << " can not move\n";
    }
    else
    {
        if (amount > this->hitPoint)
            this->hitPoint = 0;
        else
            this->hitPoint -= amount;
        std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage\n";
        if (!this->hitPoint)
            std::cout << "ClapTrap " << this->name << " died\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->hitPoint || !this->energyPoint)
    {
        std::cout << "ClapTrap " << this->name << " can not move\n";
    }
    else
    {
        this->hitPoint += amount;
        this->energyPoint--;
        std::cout << "ClapTrap " << this->name << " has been repaired of " << amount << " Hit points.";
        std::cout << " It has now " << this->hitPoint << " Hit points\n";
    }
}

std::string ClapTrap::getName() const
{
    return this->name;
}

unsigned int ClapTrap::getHitPoint() const
{
    return this->hitPoint;
}

unsigned int ClapTrap::getEnergyPoint() const
{
    return this->energyPoint;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return this->attackDamage;
}
