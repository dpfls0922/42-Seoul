/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:37:32 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/10 20:38:57 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	line;
	int			exit_status;

	while (1)
	{
		line = phoneBook.ShowPrompt();
		if (line == "exit" || line == "EXIT")
			break;
		else if (line == "add" || line == "ADD")
			exit_status = phoneBook.AddInfo();
		else if (line == "search" || line == "SEARCH")
		{
			if (phoneBook.GetSize() == 0)
			{
				std::cout << "Nothing Added. Add First\n";
				continue;
			}
			phoneBook.ShowInfo();
			phoneBook.ShowDetail();
		}
		if (exit_status == 1)
			break;
		std::cin.clear();
	}
	return (0);
}