#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap oClapTrap("1337Student");

    oClapTrap.attack("WorldWide");
    oClapTrap.beRepaired(20);

    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    // oClapTrap.beRepaired(20);
    
    oClapTrap.attack("DefaultEnemies");

    ClapTrap TwoClapTrap(oClapTrap);

    TwoClapTrap.attack("1337Staff");
    TwoClapTrap.takeDamage(1);

    return (0);
}