#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(Animal const &oAnimal)
{
    this->type = oAnimal.type;
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal &Animal::operator=(Animal const &oAnimal)
{
    this->type = oAnimal.type;
    std::cout << "Animal copy assignment operator called." << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Animal sound..." << std::endl;
}