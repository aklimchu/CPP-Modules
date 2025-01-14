#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact{
	public:
		Contact(void);
		Contact(int i, std::string first, std::string last, std::string nick,
			std::string phone, std::string secret);
		~Contact(void);
		int getIndex(void) const;
		std::string getFirst(void) const;
		std::string getLast(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getSecret(void) const;

	private:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif