#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Animal constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const &oAAnimal)
{
    this->type = oAAnimal.type;
    std::cout << "Animal copy constructor called." << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &oAAnimal)
{
    this->type = oAAnimal.type;
    std::cout << "Animal copy assignement operator called." << std::endl;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called." << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->type);
}

// void Animal::makeSound() const
// {
//     std::cout << "Animal sound..." << std::endl;
// }