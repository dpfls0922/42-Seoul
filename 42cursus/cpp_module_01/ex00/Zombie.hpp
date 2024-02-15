/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:23:13 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/12 18:39:32 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class   Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string name);
	    ~Zombie();
	    void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif