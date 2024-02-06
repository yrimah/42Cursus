#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(Cat const &oCat) : Animal(oCat)
{
    this->type = oCat.type;
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat &Cat::operator=(Cat const &oCat)
{
    this->type = oCat.type;
    std::cout << "Cat copy assignment operator called." << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
}

std::string Cat::getType() const
{
    return (this->type);
}

void Cat::makeSound() const
{
    std::cout << "Meeeeeeeeooooow..." << std::endl;
}