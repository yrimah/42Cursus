#include "Character.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = 0;
    std::cout << "Character constructor called." << std::endl;
}

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->slot[i] = 0;
    std::cout << "Character parametrized constructor called." << std::endl;
}

Character::Character(Character const &oCharacter)
{
    this->name = oCharacter.name;
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i])
			this->slot[i] = 0;
        if (oCharacter.slot[i])
            this->slot[i] = (oCharacter.slot[i])->clone();
    }
    std::cout << "Character copy constructor called." << std::endl;
}

Character &Character::operator=(Character const &oCharacter)
{
    this->name = oCharacter.name;
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i])
			delete this->slot[i];
        if (oCharacter.slot[i])
            this->slot[i] = (oCharacter.slot[i])->clone();
    }
    std::cout << "Character assignment operator called." << std::endl;

    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i])
            delete this->slot[i];
    }
    std::cout << "Character destructor called." << std::endl;
}

std::string const &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
    {
        std::cout << "Not a valid materia!!!" << std::endl;
        return;
    }
    for (int counter = 0; counter < 4; counter++)
    {
        if (this->slot[counter] == 0)
        {
            this->slot[counter] = m;
            std::cout << "Equipe complete." << std::endl;
            return;
        }
    }
    std::cout << "Equipe incomplete." << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->slot[idx])
    {
        AMateria *AMptr = (this->slot)[idx];
        this->slot[idx] = 0;
        std::cout << "Unequipe complete." << std::endl;
        return;
    }
    std::cout << "Unequipe incomplete." << std::endl;
}


void Character::use(int idx, ICharacter& target)
{
    if (slot[idx] && (idx >= 0 && idx < 4))
    {
        this->slot[idx]->use(target);
        std::cout << "Use complete." << std::endl;
        return;
    }
    std::cout << "Use incomplete." << std::endl;
}

AMateria *Character::getMateria(int idx)
{
	return (this->slot)[idx];
}