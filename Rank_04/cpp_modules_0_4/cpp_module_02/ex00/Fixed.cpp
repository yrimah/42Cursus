#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(Fixed& oFixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = oFixed.value;
}

Fixed &Fixed::operator=(const Fixed& oFixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = oFixed.value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}