#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { }

PhoneBook::~PhoneBook() { }

void	PhoneBook::add_new_contact(std::string first, \
			std::string last, std::string nickname, std::string phone, \
			std::string secret) {
	int i;
	
	if (this->number_of_contacts == 8)
		i = 0;
	else
	{
		i = this->number_of_contacts;
		this->number_of_contacts++;
	}
	this->contact[i] = Contact(i + 1, first, last, nickname, phone, secret);
}

void	PhoneBook::str_to_shorter(int i, int field_num) const {
		int	word_length;
		std::string	short_str;
		
		word_length = this->get_contact(i).getField(field_num).length();
		if (word_length > 10)
		{
			short_str = this->get_contact(i).getField(field_num).substr(0, 9);
			short_str.push_back('.');
		}
		else
			short_str = this->get_contact(i).getField(field_num);
		std::cout << "|" << std::setw(10) << short_str;
		if (field_num == 3)
			std::cout << "|" << std::endl;
}

Contact PhoneBook::get_contact(int i) const {
	return (this->contact[i]);
}


void	PhoneBook::print_all() const {
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->number_of_contacts; i++)
	{
		this->str_to_shorter(i, 0);
		this->str_to_shorter(i, 1);
		this->str_to_shorter(i, 2);
		this->str_to_shorter(i, 3);
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
};

int	PhoneBook::print_entry(int index) const {
	if (index > this->number_of_contacts - 1 || index < 0){
		std::cout << "Entry doesn't exist" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Index: " << this->contact[index].getField(0) << std::endl;
		std::cout << "First name: " << this->contact[index].getField(1) << std::endl;
		std::cout << "Last name: " << this->contact[index].getField(2) << std::endl;
		std::cout << "Nickname: " << this->contact[index].getField(3) << std::endl;
		std::cout << "Phone number: " << this->contact[index].getField(4) << std::endl;
		std::cout << "Darkest secret: " << this->contact[index].getField(5) << std::endl;
		return 0;
	}
};