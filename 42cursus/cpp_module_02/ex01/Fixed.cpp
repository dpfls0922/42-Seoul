/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:52:26 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 22:07:26 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
    this->num = 0;
}

Fixed::Fixed(int const num)
{
    std::cout << "Int constructor called\n";
    this->num = num << this->bits;
}

Fixed::Fixed(float const num)
{
    std::cout << "Float constructor called\n";
	this->num = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
    *this = obj;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed   &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
    if (this != &obj)
        this->num = obj.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

int     Fixed::getRawBits(void) const
{
    return (this->num);
}

void    Fixed::setRawBits(int const raw)
{
    this->num = raw;
}

float   Fixed::toFloat(void) const
{
	return ((float)this->num / (1 << this->bits)); 
}

int     Fixed::toInt(void) const
{
	return (this->num >> this->bits);
}