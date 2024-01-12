/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:37:32 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/12 16:49:31 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	line;

	while (1)
	{
		line = phoneBook.ShowPrompt();
		if (line == "exit" || line == "EXIT")
			break;
		else if (line == "add" || line == "ADD")
			phoneBook.AddInfo();
		else if (line == "search" || line == "SEARCH")
		{
			if (phoneBook.GetSize() == 0)
			{
				std::cout << "| Error: Nothing to search\n\n";
				continue;
			}
			phoneBook.ShowAllInfo();
			phoneBook.ShowDetail();
		}
		std::cin.clear();
	}
	return (0);
}