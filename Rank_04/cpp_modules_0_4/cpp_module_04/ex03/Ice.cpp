#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructor called." << std::endl;
}

Ice::Ice(Ice const &oIce) : AMateria("ice")
{
    (*this) = oIce;
    std::cout << "Ice copy constructor called." << std::endl;
}

Ice &Ice::operator=(Ice const &oIce)
{
    // this->type = oIce.type; // See the tips
    std::cout << "Ice assignment operator called." << std::endl;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone() const
{
    Ice* oIce = new Ice();
    return (oIce);
}

void Ice::use(ICharacter& target)
{
    std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}