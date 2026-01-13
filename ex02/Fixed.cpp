#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::Fixed(const int intValue)
{
    this->fixedPointValue = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    this->fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
        this->fixedPointValue = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
}

// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->fixedPointValue > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->fixedPointValue < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->fixedPointValue >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->fixedPointValue <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->fixedPointValue == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->fixedPointValue != rhs.getRawBits());
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment/Decrement operators
Fixed& Fixed::operator++(void)
{
    this->fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixedPointValue++;
    return (temp);
}

Fixed& Fixed::operator--(void)
{
    this->fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixedPointValue--;
    return (temp);
}

// Member functions
int Fixed::getRawBits(void) const
{
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->fixedPointValue / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->fixedPointValue >> fractionalBits);
}

// Static member functions
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

// Stream insertion operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

