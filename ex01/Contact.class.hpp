#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <sstream>
# include <iomanip>

class Contact{
	public:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number; // private?
		std::string	darkest_secret; // private?

		Contact(void);
		~Contact(void);
};

#endif