#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &oWrongAnimal)
{
    this->type = oWrongAnimal.type;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &oWrongAnimal)
{
    this->type = oWrongAnimal.type;
    std::cout << "WrongAnimal copy assignment operator called." << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound..." << std::endl;
}