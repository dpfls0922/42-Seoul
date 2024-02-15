/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:27:28 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 21:12:01 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
    this->num = 0;
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

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (this->num);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->num = raw;
}
