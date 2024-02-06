#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie randomZ = Zombie();
    randomZ.setName(name);
    randomZ.annouce();
}