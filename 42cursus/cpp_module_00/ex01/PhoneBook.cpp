/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:37:23 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/11 17:56:58 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){this->i = -1;}

PhoneBook::~PhoneBook(){}

std::string PhoneBook::ShowPrompt(void)
{
    std::cout << "+-------------------------------------------+\n";
    std::cout << "|       Actions : (ADD, SEARCH, EXIT)       |\n";
    std::cout << "+-------------------------------------------+\n";
    std::cout << "| Please enter your action : ";
    std::getline(std::cin, this->line);
    if (std::cin.eof())
        return ("EXIT");
    std::cout << std::endl;
    return this->line;
}

std::string PhoneBook::ReadLine(std::string str)
{
    std::string input;

    while(input.empty())
    {
        std::cout << str;
        std::getline(std::cin, input);
        if (std::cin.eof())
            return "";
    }
    return input;
}

int    PhoneBook::AddInfo(void)
{
    std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

    if (this->i == 7) this->i = 0;
	else this->i++;
    firstName = ReadLine("| Enter First Name : ");
    lastName = ReadLine("| Enter Last Name : ");
    nickname = ReadLine("| Enter Nick Name : ");
    phoneNumber = ReadLine("| Enter Phone Number : ");
    darkestSecret = ReadLine("| Enter Darkest Secret : ");
    contact[this->i].SetInfo(firstName, lastName, nickname, phoneNumber, darkestSecret);
    std::cout << "\n\n";
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
        return (1);
    return (0);
}

int    PhoneBook::GetSize(void){return this->i + 1;};

void    PhoneBook::ShowAllInfo(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;

	std::cout << "+-------------------------------------------+\n";
	for (int i = 0; i <= this->i && i < 8; i++)
	{
		firstName = contact[i].GetFirstName();
		lastName = contact[i].GetLastName();
		nickName = contact[i].GetNickName();
		if (firstName.length() > 10)
			firstName.replace(9, firstName.length() - 9, ".");
		if (lastName.length() > 10)
			lastName.replace(9, lastName.length() - 9, ".");
		if (nickName.length() > 10)
			nickName.replace(9, nickName.length() - 9, ".");
		std::cout << "|";
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << firstName << "|";
		std::cout << std::setw(10) << lastName << "|";
		std::cout << std::setw(10) << nickName << "|";
		std::cout << "\n";
		std::cout << "+-------------------------------------------+\n";
	}
}

int    PhoneBook::GetContactIndex(void)
{
	std::string str;
	int			n;

	std::cout << "| Enter the Contact index : ";
	std::getline(std::cin, str);
	if (str.empty() || std::cin.eof())
		return (-1);
	for (unsigned int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "| Error: Not Numeric Type\n";
			return (-1);
		}
	}
	n = std::stoi(str);
	if (!(n >= 1 && n <= 8 && n <= this->i + 1))
	{
		std::cout << "| Error: Input Out Of Range\n";
		return (-1);
	}
	return (n);
}

int    PhoneBook::ShowDetail(void)
{
    int id;

    id = GetContactIndex() - 1;
    if (id >= 0 && id <= 7)
    {
		std::cout << "+--------------------------------------------\n";
		std::cout << "| First Name	: ";
		std::cout << contact[id].GetFirstName() << "\n";
		std::cout << "| Last Name	: ";
		std::cout << contact[id].GetLastName() << "\n";
		std::cout << "| NickName	: ";
		std::cout << contact[id].GetNickName() << "\n";
		std::cout << "| PhoneNumber	: ";
		std::cout << contact[id].GetPhoneNumber() << "\n";
		std::cout << "| A Secret	: ";
		std::cout << contact[id].GetDarkestSecret() << "\n";
		std::cout << "+--------------------------------------------\n";
	}
	std::cout << "\n";
	return (0);
}