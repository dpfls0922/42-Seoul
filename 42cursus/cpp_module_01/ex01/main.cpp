/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:03:44 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 11:05:20 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *horde;

	horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
	    horde->announce();
	delete [] horde;
    return (0);
}