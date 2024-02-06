#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class Zombie
{
	private:
	       std::string name;
	       
	public:
	       Zombie();
	       ~Zombie();
	       void annouce(void) const;
	       void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
