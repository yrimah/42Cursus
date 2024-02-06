#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

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

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
