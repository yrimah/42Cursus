#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int int_value);
        Fixed(const float float_value);
        Fixed(const Fixed& oFixed);
        Fixed& operator=(const Fixed& oFixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
