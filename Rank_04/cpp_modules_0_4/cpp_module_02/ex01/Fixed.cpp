#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& oFixed)
{
    this->value = oFixed.value;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
    this->value = int_value << fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value)
{
    this->value = std::roundf(float_value * (1 << fractionalBits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& oFixed)
{
    this->value = oFixed.value;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->getRawBits()) / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->value >> fractionalBits);
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &oFixed)
{
    ostream << oFixed.toFloat();
    return (ostream);
}