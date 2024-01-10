/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:37:23 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/10 20:40:04 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){this->i = -1;}

std::string PhoneBook::ShowPrompt(void)
{
    std::cout << "|----------|----------|----------|\n";
    std::cout << "| Actions : (ADD, SEARCH, EXIT)  |\n";
    std::cout << "|----------|----------|----------|\n";
    std::cout << "| Please enter your action : ";
    std::getline(std::cin, this->line);
    if (std::cin.eof())
        return ("EXIT");
    std::cout << std::endl;
    return this->line;
}

std::string PhoneBook::readLine(std::string str)
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
    std::cout << "|--------------------------------|\n";
    firstName = readLine("Enter First Name : ");
    std::cout << "|--------------------------------|\n";
    lastName = readLine("Enter Last Name : ");
    std::cout << "|--------------------------------|\n";
    nickname = readLine("Enter Nick Name : ");
    std::cout << "|--------------------------------|\n";
    phoneNumber = readLine("Enter Phone Number : ");
    std::cout << "|--------------------------------|\n";
    darkestSecret = readLine("Enter Darkest Secret : ");
    contact[this->i].SetInfo(firstName, lastName, nickname, phoneNumber, darkestSecret);
    std::cout << "|--------------------------------|\n";
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
        return (1);
    return (0);
}

int    PhoneBook::GetSize(void){return this->i;};

void    PhoneBook::ShowInfo(void)
{
    
}

void    PhoneBook::ShowDetail(void)
{
    
}