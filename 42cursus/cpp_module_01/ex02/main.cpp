/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:13:07 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 11:36:05 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "----------------\n";
    std::cout << " Memory Address\n";
    std::cout << "----------------\n";
    std::cout << &str << "\n";
    std::cout << stringPTR << "\n";
    std::cout << &stringREF << "\n";

    std::cout << "----------------\n";
    std::cout << " String Value\n";
    std::cout << "----------------\n";
    std::cout << str << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";
}