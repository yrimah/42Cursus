#include "Zombie.hpp"

int main(void)
{
	std::cout << "----FIRST TEST----" << std::endl;
	Zombie z1;

	z1.setName("Z1");
	z1.annouce();
	z1.setName("z1");
	z1.annouce();

	std::cout << "----SECOND TEST----" << std::endl;

	randomChump("Z2");
	
	std::cout << "----THIRD TEST----" << std::endl;

	Zombie *z3;

	z3 = newZombie("Z3");
	z3->annouce();
	// z3->~Zombie();
	delete(z3);
	return (0);
}
