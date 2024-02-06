#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap &oFragTrap);
        FragTrap &operator=(FragTrap &oFragTrap);
        ~FragTrap();

        void highFivesGuys(void) const;
};

#endif