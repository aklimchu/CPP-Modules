#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(){
	std::cout << "PhoneBook constructor called" << std::endl;
	return ;
}


PhoneBook::~PhoneBook(){
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

void	PhoneBook::add_new_contact(std::string first, \
			std::string last, std::string nickname, std::string phone, \
			std::string secret){
	int i;
	
	if (PhoneBook::number_of_contacts == 8)
		i = 0;
	else
	{
		i = PhoneBook::number_of_contacts;
		PhoneBook::number_of_contacts++;
	}
	PhoneBook::contact[i].index = i + 1;
	PhoneBook::contact[i].first_name = first;
	PhoneBook::contact[i].last_name = last;
	PhoneBook::contact[i].nickname = nickname;
	PhoneBook::contact[i].phone_number = phone;
	PhoneBook::contact[i].darkest_secret = secret;
}

void	PhoneBook::print_all() const{
	for (int i = 0; i < PhoneBook::number_of_contacts; i++)
	{
		std::cout << "Index: " << PhoneBook::contact[i].index << std::endl;
		std::cout << "First name: " << PhoneBook::contact[i].first_name << std::endl;
		std::cout << "Last name: " << PhoneBook::contact[i].last_name << std::endl;
		std::cout << "Nickname: " << PhoneBook::contact[i].nickname << std::endl;
	}
};