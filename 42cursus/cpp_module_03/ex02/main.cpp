
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap A("A");
	ClapTrap B("B");
	FragTrap C("C");
	ClapTrap D(B);

	A.attack("B");
	C.takeDamage(2);
	C.beRepaired(2);
	C.takeDamage(10);
	A.takeDamage(50);
	C.attack("A");
	A.guardGate();
	D.attack("B");
	C.highFivesGuys();
}