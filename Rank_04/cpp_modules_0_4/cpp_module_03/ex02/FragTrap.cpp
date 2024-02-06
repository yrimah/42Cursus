#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "[ FragTrap ] : Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "[ FragTrap ] : Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &oFragTrap) : ClapTrap(oFragTrap)
{
    std::cout << "[ FragTrap ] : Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &oFragTrap)
{
    this->name = oFragTrap.name;
    this->hit_points = oFragTrap.hit_points;
    this->energy_points = oFragTrap.energy_points;
    this->attack_damage = oFragTrap.attack_damage;
    
    std::cout << "[ FragTrap ] : Copy assignment operator called" << std::endl;

    return (*this);
}

FragTrap::~FragTrap()
{
     std::cout << "[ FragTrap ] : Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
    std::cout << "[ FragTrap ] : High fives you guys" << std::endl;
}