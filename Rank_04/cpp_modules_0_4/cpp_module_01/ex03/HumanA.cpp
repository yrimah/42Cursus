#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
    this->name = name;
    this->weapon = &weapon;
}

HumanA::~HumanA()
{
}

void HumanA::attack(void) const
{
    std::cout << this->name << "  attacks with their " << this->weapon->getType() << std::endl;
}