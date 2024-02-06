#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& oFixed)
{
    this->value = oFixed.value;
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
    this->value = int_value << fractionalBits;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value)
{
    this->value = std::roundf(float_value * (1 << fractionalBits));
    // std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& oFixed)
{
    this->value = oFixed.value;
    // std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator>(const Fixed &oFixed) const
{
    return (this->value > oFixed.value);
}

bool Fixed::operator<(const Fixed &oFixed) const
{
    return (this->value < oFixed.value);
}

bool Fixed::operator>=(const Fixed &oFixed) const
{
    return (this->value >= oFixed.value);
}

bool Fixed::operator<=(const Fixed &oFixed) const
{
    return (this->value <= oFixed.value);
}

bool Fixed::operator==(const Fixed &oFixed) const
{
    return (this->value == oFixed.value);
}

bool Fixed::operator!=(const Fixed &oFixed) const 
{
    return (this->value != oFixed.value);
}

// Call the float constructor inside those functions

Fixed Fixed::operator+(const Fixed &oFixed) const
{
    Fixed newFixed(this->toFloat() + oFixed.toFloat());
    return (newFixed);
}
Fixed Fixed::operator-(const Fixed &oFixed) const
{
    Fixed newFixed(this->toFloat() - oFixed.toFloat());
    return (newFixed);
}
Fixed Fixed::operator*(const Fixed &oFixed) const
{
    Fixed newFixed(this->toFloat() * oFixed.toFloat());
    return (newFixed);
}
Fixed Fixed::operator/(const Fixed &oFixed) const
{
    Fixed newFixed(this->toFloat() / oFixed.toFloat());
    return (newFixed);
}


Fixed &Fixed::operator++()
{
    ++this->value;
    return (*this);
}

// Call the copy constructor in the post increment

Fixed Fixed::operator++(int)
{
    Fixed oFixed(*this);
    oFixed.value = this->value++;
    return (oFixed);
}

Fixed &Fixed::operator--()
{
    --this->value;
    return (*this);
}

// Call the copy constructor in the post decrement

Fixed Fixed::operator--(int)
{
    Fixed oFixed(*this);
    oFixed.value = this->value--;
    return (oFixed);
}

Fixed& Fixed::min(Fixed &fixedPointOne, Fixed &fixedPointTwo)
{
    if (fixedPointOne.value < fixedPointTwo.value)
        return (fixedPointOne);
    return (fixedPointTwo);
}

const Fixed& Fixed::min(const Fixed &fixedPointOne, const Fixed &fixedPointTwo)
{
    if (fixedPointOne.value < fixedPointTwo.value)
        return (fixedPointOne);
    return (fixedPointTwo);
}

Fixed& Fixed::max(Fixed &fixedPointOne, Fixed &fixedPointTwo)
{
    if (fixedPointOne.value > fixedPointTwo.value)
        return (fixedPointOne);
    return (fixedPointTwo);
}

const Fixed& Fixed::max(const Fixed &fixedPointOne, const Fixed &fixedPointTwo)
{
    if (fixedPointOne.value > fixedPointTwo.value)
        return (fixedPointOne);
    return (fixedPointTwo);
}