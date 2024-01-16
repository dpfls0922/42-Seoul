/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:03:44 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/16 19:37:35 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie global_stack("Data Zombie");
    Zombie *heap;

    randomChump("Stack Zombie");
    heap = newZombie("Heap Zombie");
    heap->announce();
    delete heap;
    return (0);
}