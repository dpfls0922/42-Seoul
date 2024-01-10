/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:37:07 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/10 19:37:08 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class	Contact{
	private:
		std::string  firstName;
		std::string  lastName;
		std::string  nickName;
		std::string  phoneNumber;
		std::string  darkestSecret;

	public:
		void setInfo(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string DdarkestSecret
		);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif