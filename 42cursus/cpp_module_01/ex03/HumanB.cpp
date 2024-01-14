/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:39:32 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 13:55:23 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (weapon)
    {
        std::cout << this->name << " attacks with their ";
        std::cout << this->weapon->getType() << "\n";
    }
    else
        std::cout << this->name << " attacks with no item " << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}