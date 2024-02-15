
#include "Fixed.hpp"

Fixed::Fixed()
{
    this->num = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int num)
{
    this->num = num << this->bits;
}

Fixed::Fixed(const float num)
{
    this->num = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

float   Fixed::toFloat(void) const
{
	return ((float)this->num / (1 << this->bits)); 
}

int     Fixed::toInt(void) const
{
	return (this->num >> this->bits);
}

int     Fixed::getRawBits(void) const
{
    return (this->num);
}

void    Fixed::setRawBits(int const raw)
{
    this->num = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

Fixed   &Fixed::operator=(const Fixed &obj)
{
    if (this != &obj)
        this->num = obj.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &obj) const
{
    return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
    return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (this->getRawBits() != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const
{
    return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    return Fixed(this->toFloat() / obj.toFloat());
}


Fixed& Fixed::operator++(void)
{
    this->num++;
    return (*this);
}

Fixed& Fixed::operator--(void)
{
    this->num--;
    return (*this);
}

const Fixed Fixed::operator++(int)
{
    const Fixed fixed(*this);
    this->num++;
    return (fixed);
}

const Fixed Fixed::operator--(int)
{
    const Fixed fixed(*this);
    this->num--;
    return (fixed);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
    if (fix1 <= fix2)
        return (fix1);
    return (fix2);
}

const Fixed& Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 <= fix2)
        return (fix1);
    return (fix2);
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2)
{
    if (fix1 >= fix2)
        return (fix1);
    return (fix2);
}

const Fixed& Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 >= fix2)
        return (fix1);
    return (fix2);
}