/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:03:44 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/12 21:33:30 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie global_stack("Global Stack Zombie");
    Zombie *heap;

    randomChump("Local Stack Zombie");
    heap = newZombie("Heap Zombie");
    heap->announce();
    delete heap;
    return (0);
}