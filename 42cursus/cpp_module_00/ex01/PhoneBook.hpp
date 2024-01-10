/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:37:27 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/10 20:39:01 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook{
	private:
		Contact contact[8];
		int			i;
		std::string	line;

	public:
		PhoneBook();
		~PhoneBook();
		std::string ShowPrompt();
		std::string PhoneBook::readLine(std::string str);
		int			AddInfo();
		int			GetSize();
		void		ShowInfo();
		void		ShowDetail();
};

#endif