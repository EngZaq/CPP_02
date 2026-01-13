#include "Fixed.hpp"

Fixed :: Fixed()
{
    this -> fixedPointValue = 0;   
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return (this -> fixedPointValue);
}

void Fixed :: setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this -> fixedPointValue = raw;
}

