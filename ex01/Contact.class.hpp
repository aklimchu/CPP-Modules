#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>

class Contact{
	public:
		std::string	first_name; // do we need to allocate?
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number; // private?
		std::string	darkest_secret; // private?

		Contact(void); // what arguments?
		~Contact(void);
	//private:
};

#endif