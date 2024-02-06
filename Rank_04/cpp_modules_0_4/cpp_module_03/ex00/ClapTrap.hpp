#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    private:
        std::string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;
    
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap &oClapTrap);
        ClapTrap &operator=(ClapTrap &oClapTrap);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
};

#endif