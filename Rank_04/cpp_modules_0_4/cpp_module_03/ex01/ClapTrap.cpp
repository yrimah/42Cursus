# include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "[ ClapTrap ] : Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "[ ClapTrap ] : Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &oClapTrap)
{
    this->name = oClapTrap.name;
    this->hit_points = oClapTrap.hit_points;
    this->energy_points = oClapTrap.energy_points;
    this->attack_damage = oClapTrap.attack_damage;
    std::cout << "[ ClapTrap ] : Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &oClapTrap)
{
    this->name = oClapTrap.name;
    this->hit_points = oClapTrap.hit_points;
    this->energy_points = oClapTrap.energy_points;
    this->attack_damage = oClapTrap.attack_damage;
    std::cout << "[ ClapTrap ] : Copy assignment operator called" << std::endl;
    
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ ClapTrap ] : Destructor called" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points >= amount)
    {
        this->hit_points -= amount;
        std::cout << "[ " << this->name << " ] : " << amount << " points of damage : Complete | Hit points left : " << this->hit_points << " | Energy points left : " << this->energy_points << std::endl;
    }
    else
        std::cout << "Player about to die ..." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points != 0 && this->energy_points != 0)
    {
        this->energy_points--;
        std::cout << "ClapTrap [ "<< this->name << " ] attacks [ " << target << " ] , causing " << this->attack_damage << " points of damage! | Hit points left : " << this->hit_points << " | Energy points left : " << this->energy_points << std::endl;
        return ;
    }
    std::cout << "[ " << this->name << " ] : No enough hit points/energy points to attack !!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points != 0)
    {
        this->hit_points += amount;
        this->energy_points--;
        std::cout << "[ " << this->name << " ] : Reparation complete. | Hit points left : " << this->hit_points << " | Energy points left : " << this->energy_points << std::endl;
        return ;
    }
    std::cout << "[ " << this->name << " ] : No enough energy points to attack !!" << std::endl;
}