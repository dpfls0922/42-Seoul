/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:46:00 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 19:15:59 by yerilee          ###   ########.fr       */
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
        Fixed(const Fixed &obj);
        ~Fixed();
        Fixed   &operator=(const Fixed &obj);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif