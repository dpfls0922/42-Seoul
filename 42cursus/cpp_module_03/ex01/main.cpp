
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");
	a.attack("B");
	b.takeDamage(10);
	b.beRepaired(2);
	a.guardGate();
}