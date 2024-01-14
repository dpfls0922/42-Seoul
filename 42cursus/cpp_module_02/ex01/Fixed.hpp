/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:49:50 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 21:56:46 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 num;
        static const int    bits = 8;
    public:
        Fixed();
        Fixed(int const num);
        Fixed(float const num);
        Fixed(const Fixed &obj);
        ~Fixed();
        Fixed   &operator=(const Fixed &obj);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &obj);
#endif