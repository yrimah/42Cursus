#include "AMateria.hpp"

AMateria::AMateria()
{
     std::cout << "AMateria constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
    std::cout << "AMateria parameterized constructor called." << std::endl;
}

AMateria::AMateria(AMateria const &oAMateria)
{
    *this = oAMateria;
    std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria &AMateria::operator=(AMateria const &oAMateria)
{
    *this = oAMateria;
    std::cout << "AMateria assignment operator called." << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called." << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "[ " << target.getName() << " ] : use AMateria : [ " << this->type << " ]" << std::endl;
}