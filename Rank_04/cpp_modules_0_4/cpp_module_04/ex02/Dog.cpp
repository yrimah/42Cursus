#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog constructor called." << std::endl;
    this->oBrain = new Brain();
}

Dog::Dog(Dog const &oDog) : AAnimal(oDog)
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->type = oDog.type;
    this->oBrain = new Brain();
    // this->oBrain = oDog.oBrain;
}

Dog &Dog::operator=(Dog const &oDog)
{
    std::cout << "Dog copy assignment operator called." << std::endl;
    this->type = oDog.type;
    this->oBrain = new Brain(*oDog.oBrain);
    return (*this);
}

Dog::~Dog()
{
    delete oBrain;
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