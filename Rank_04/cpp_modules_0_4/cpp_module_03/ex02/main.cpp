#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap oClapTrap("1337Student");

    oClapTrap.attack("WorldWide");
    oClapTrap.beRepaired(200);
    // oClapTrap.attack("DefaultEnemies");

    // ClapTrap TwoClapTrap(oClapTrap);

    // TwoClapTrap.attack("1337Staff");
    // TwoClapTrap.takeDamage(1);

    // ScavTrap oScavTrap("Yassine");

    // oScavTrap.attack("OwnSpace");
    // oScavTrap.beRepaired(1337);

    FragTrap oFragTrap("GredOne");

    oFragTrap.attack("LittleMiss");
    oFragTrap.beRepaired(42);
	oFragTrap.highFivesGuys();
    
    return (0);
}
