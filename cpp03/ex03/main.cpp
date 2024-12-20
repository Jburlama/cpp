#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap foo("Quim");

	std::cout << "\n";
	foo.whoAmI();
	foo.attack("ze");
	std::cout << "\n";
}
