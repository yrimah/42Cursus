#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructor called." << std::endl;
}

Cure::Cure(Cure const &oCure) : AMateria("cure")
{
    (*this) = oCure;
    std::cout << "Cure copy constructor called." << std::endl;
}

Cure &Cure::operator=(Cure const &oCure)
{
    // this->type = oCure.type; // See the tips
    std::cout << "Cure assignment operator called." << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone() const
{
    Cure* oCure = new Cure();
    return (oCure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
}