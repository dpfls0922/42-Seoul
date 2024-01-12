/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:23:13 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/12 21:44:33 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class   Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
	    ~Zombie();
	    void announce();
        void setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif