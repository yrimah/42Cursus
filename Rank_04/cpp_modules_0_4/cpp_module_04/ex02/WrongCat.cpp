#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &oWrongCat) : WrongAnimal(oWrongCat)
{
    this->type = oWrongCat.type;
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &oWrongCat)
{
    this->type = oWrongCat.type;
    std::cout << "WrongCat copy assignment operator called." << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called." << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->type);
}

void WrongCat::makeSound() const
{
    std::cout << "Meeeeeeeeooooow..." << std::endl;
}