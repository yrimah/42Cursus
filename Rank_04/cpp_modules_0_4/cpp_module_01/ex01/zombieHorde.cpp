#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *nZombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		nZombie[i].setName(name);
	return (nZombie);
}
