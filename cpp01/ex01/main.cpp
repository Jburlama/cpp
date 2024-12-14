#include "Zombie.hpp"

int main()
{
	Zombie *horde;

	horde = zombieHorde(5, "zé");
	if (horde == NULL)
		return (0);
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	 delete[] horde;
}
