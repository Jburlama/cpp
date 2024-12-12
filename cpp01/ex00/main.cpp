#include "Zombie.hpp"

int main( void )
{
	Zombie *ze;
	ze = newZombie("ze");
	ze->announce();
	randomChump("Quim");
	delete ze;
	return (0);
}
