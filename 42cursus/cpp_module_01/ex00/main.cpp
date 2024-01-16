/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:03:44 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/16 19:46:10 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie stack_zombie("Stack Zombie");
    Zombie *heap;

    randomChump("Function Zombie");
    heap = newZombie("Heap Zombie");
    heap->announce();
    delete heap;
    return (0);
}