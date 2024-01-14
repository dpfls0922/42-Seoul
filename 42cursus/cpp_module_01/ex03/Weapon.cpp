/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:08:44 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 13:11:27 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    
}

const std::string &Weapon::getType() const
{
    return (this->type);
}

void Weapon::setType(const std::string type)
{
    this->type = type;
}