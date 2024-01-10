/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:37:05 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/10 19:37:05 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirstName() {return this->firstName;}
std::string	Contact::getLastName() {return this->lastName;}
std::string	Contact::getNickName() {return this->nickName;}
std::string	Contact::getPhoneNumber() {return this->phoneNumber;}
std::string	Contact::getDarkestSecret() {return this->darkestSecret;}

void	Contact::setInfo(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}
