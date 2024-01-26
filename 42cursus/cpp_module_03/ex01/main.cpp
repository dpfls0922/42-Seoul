
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap *parent;
	parent = new ScavTrap("child");

	ScavTrap a("A");
	ScavTrap b("B");
	a.attack("B");
	parent->attack("B");
	b.takeDamage(10);
	b.beRepaired(2);
	a.guardGate();
}