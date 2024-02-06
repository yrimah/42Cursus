#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(Dog const &oDog) : Animal(oDog)
{
    this->type = oDog.type;
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog &Dog::operator=(Dog const &oDog)
{
    this->type = oDog.type;
    std::cout << "Dog copy assignment operator called." << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
}

std::string Dog::getType() const
{
    return (this->type);
}

void Dog::makeSound() const
{
    std::cout << "Baaaaaaaaaaaaark..." << std::endl;
}