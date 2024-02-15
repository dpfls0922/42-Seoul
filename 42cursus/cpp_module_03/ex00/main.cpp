
#include "ClapTrap.hpp"

int	main(void)
{
    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    std::cout << "a : getAttackDamage " << a.getAttackDamage() << std::endl;
    std::cout << "a : getEnergyPoint " << a.getEnergyPoint() << std::endl;
    std::cout << "a : getHitPoint " << a.getHitPoint() << std::endl;
    b.takeDamage(5);
    std::cout << "b : getAttackDamage " << b.getAttackDamage() << std::endl;
    std::cout << "b : getEnergyPoint " << b.getEnergyPoint() << std::endl;
    std::cout << "b : getHitPoint " << b.getHitPoint() << std::endl;
    b.beRepaired(3);
    std::cout << "b : getAttackDamage " << b.getAttackDamage() << std::endl;
    std::cout << "b : getEnergyPoint " << b.getEnergyPoint() << std::endl;
    std::cout << "b : getHitPoint " << b.getHitPoint() << std::endl;
    b.attack("A");
    a.takeDamage(10);
    std::cout << "a : getAttackDamage " << a.getAttackDamage() << std::endl;
    std::cout << "a : getEnergyPoint " << a.getEnergyPoint() << std::endl;
    std::cout << "a : getHitPoint " << a.getHitPoint() << std::endl;
    a.beRepaired(10);
    std::cout << "a : getAttackDamage " << a.getAttackDamage() << std::endl;
    std::cout << "a : getEnergyPoint " << a.getEnergyPoint() << std::endl;
    std::cout << "a : getHitPoint " << a.getHitPoint() << std::endl;
}