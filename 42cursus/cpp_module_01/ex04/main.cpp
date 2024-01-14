/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:17:52 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/14 15:14:37 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
        return (0);
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream inFile;
    std::ofstream outFile;
    std::string   line;
    std::size_t   pos;

    if (s1.size() == 0 || s2.size() == 0)
        return (0);
    inFile.open(filename);
    if (inFile.is_open())
    {
        std::getline(inFile, line, '\0');
        pos = 0;
        while ((pos = line.find(s1, pos)) != line.npos)
        {
            line.erase(pos, s1.size());
            line.insert(pos, s2);
        }
        outFile.open(filename + ".replace");
        if (outFile.is_open())
            outFile << line;
    }
    inFile.close();
    outFile.close();
}