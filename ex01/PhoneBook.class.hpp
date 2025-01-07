#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_new_contact(std::string first, \
			std::string last, std::string nickname, std::string phone, \
			std::string secret);
		void	print_all() const;
		int		print_entry(int entry_index) const;
	
	private:
		Contact contact[8];
		int		number_of_contacts = 0;
};

#endif