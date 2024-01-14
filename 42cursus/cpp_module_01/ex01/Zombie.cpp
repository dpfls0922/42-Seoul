/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:36:09 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 11:05:24 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    
}

Zombie::~Zombie()
{
    std::cout << this->name << " : ";
    std::cout << "is dead\n";
}

void Zombie::announce()
{
    std::cout << this->name << " : ";
    std::cout << "BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
