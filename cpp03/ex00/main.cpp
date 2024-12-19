#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	ze("ze");
	ClapTrap	pedro( ze );
	ClapTrap	joao;

	joao = ze;

	ze.attack("Quim");
	pedro.attack("Quim");
	joao.attack("Quim");

	ze.takeDamage(10);
	pedro.takeDamage(5);
	joao.takeDamage(25);

	ze.beRepaired(10);
	pedro.beRepaired(5);
	joao.beRepaired(25);
}
