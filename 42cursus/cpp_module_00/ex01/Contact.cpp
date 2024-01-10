/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:37:05 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/10 19:55:03 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::GetFirstName() {return this->firstName;}
std::string	Contact::GetLastName() {return this->lastName;}
std::string	Contact::GetNickName() {return this->nickName;}
std::string	Contact::GetPhoneNumber() {return this->phoneNumber;}
std::string	Contact::GetDarkestSecret() {return this->darkestSecret;}

void	Contact::SetInfo(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}
