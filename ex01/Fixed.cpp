#include "Fixed.hpp"

Fixed :: Fixed()
{
    this -> fixedPointValue = 0;   
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}


Fixed :: Fixed(const Fixed &zaid)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = zaid;
}

Fixed& Fixed :: operator=(const Fixed &zaid)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &zaid)
        this -> fixedPointValue = zaid.getRawBits();
    return (*this);
}

Fixed :: ~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits( void ) const
{
    return (this -> fixedPointValue);
}

void Fixed :: setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this -> fixedPointValue = raw;
}

float Fixed :: toFloat(void) const
{
    return ((float)this->fixedPointValue / (1 << fractionalBits));
}

int Fixed :: toInt(void) const
{
    return (this->fixedPointValue >> fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &zaid)
{
    out << zaid.toFloat();
    return (out);
}