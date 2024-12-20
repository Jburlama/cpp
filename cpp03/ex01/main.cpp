#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap foo("zé");
	std::cout << "\n";

	foo.attack("Quim");
	foo.takeDamage(10);
	foo.beRepaired(10);
	foo.guardGate();
	std::cout << "\n";
}
