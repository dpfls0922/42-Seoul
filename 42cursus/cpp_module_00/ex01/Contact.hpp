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