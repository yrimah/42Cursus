# include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "[ ScavTrap ] : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "[ ScavTrap ] : Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &oScavTrap) : ClapTrap(oScavTrap)
{
    std::cout << "[ ScavTrap ] : Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &oScavTrap)
{
    this->name = oScavTrap.name;
    this->hit_points = oScavTrap.hit_points;
    this->energy_points = oScavTrap.energy_points;
    this->attack_damage = oScavTrap.attack_damage;
    
    std::cout << "[ ScavTrap ] : Copy assignment operator called" << std::endl;

    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ ScavTrap ] : Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_points != 0 && this->energy_points != 0)
    {
        this->energy_points--;
        std::cout << "ScavTrap [ "<< this->name << " ] attacks [ " << target << " ] , causing " << this->attack_damage << " points of damage! | Hit points left : " << this->hit_points << " | Energy points left : " << this->energy_points << std::endl;
        return ;
    }
    std::cout << "[ " << this->name << " ] : No enough hit points/energy points to attack !!" << std::endl;
}

void ScavTrap::guardGate() const
{
    std::cout << "[ ScavTrap ] : is now in Gate keeper mode." << std::endl;
}