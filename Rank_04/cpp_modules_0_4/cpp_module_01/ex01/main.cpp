#include "Zombie.hpp"

int main(void)
{
	Zombie *multiZombie = zombieHorde(5, "1337zombie");

	//Zombie annouce
	
	for (int i = 0; i < 5; i++)
		multiZombie[i].annouce();
	
	//Zombie destruct
	
	delete[] multiZombie;
	return (0);
}
