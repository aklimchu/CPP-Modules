#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	return ;
}


PhoneBook::~PhoneBook(){
	return ;
}

void	PhoneBook::add_new_contact(std::string first, \
			std::string last, std::string nickname, std::string phone, \
			std::string secret){
	int i;
	
	if (this->number_of_contacts == 8)
		i = 0;
	else
	{
		i = this->number_of_contacts;
		this->number_of_contacts++;
	}
	this->contact[i].index = i + 1;
	this->contact[i].first_name = first;
	this->contact[i].last_name = last;
	this->contact[i].nickname = nickname;
	this->contact[i].phone_number = phone;
	this->contact[i].darkest_secret = secret;
}

void	PhoneBook::print_all() const{
	int			word_length;
	std::string	index_str;
	std::string	short_str;
	
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->number_of_contacts; i++)
	{
		index_str.clear();
		short_str.clear();
		index_str = std::to_string(this->contact[i].index);
		word_length = index_str.length();
		if (word_length > 10)
		{
			short_str = index_str.substr(0, 9);
			short_str.push_back('.');
		}
		else
			short_str = index_str;
		std::cout << "|" << std::setw(10) << short_str;

		short_str.clear();
		word_length = this->contact[i].first_name.length();
		if (word_length > 10)
		{
			short_str = this->contact[i].first_name.substr(0, 9);
			short_str.push_back('.');
		}
		else
			short_str = this->contact[i].first_name;
		std::cout << "|" << std::setw(10) << short_str;

		short_str.clear();
		word_length = this->contact[i].last_name.length();
		if (word_length > 10)
		{
			short_str = this->contact[i].last_name.substr(0, 9);
			short_str.push_back('.');
		}
		else
			short_str = this->contact[i].last_name;
		std::cout << "|" << std::setw(10) << short_str;

		short_str.clear();
		word_length = this->contact[i].nickname.length();
		if (word_length > 10)
		{
			short_str = this->contact[i].nickname.substr(0, 9);
			short_str.push_back('.');
		}
		else
			short_str = this->contact[i].nickname;
		std::cout << "|" << std::setw(10) << short_str << "|" << std::endl;

		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
};

int	PhoneBook::print_entry(int index) const{
	if (index > this->number_of_contacts - 1 || index < 0){
		std::cout << "Entry doesn't exist" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Index: " << this->contact[index].index << std::endl;
		std::cout << "First name: " << this->contact[index].first_name << std::endl;
		std::cout << "Last name: " << this->contact[index].last_name << std::endl;
		std::cout << "Nickname: " << this->contact[index].nickname << std::endl;
		std::cout << "Phone number: " << this->contact[index].phone_number << std::endl;
		std::cout << "Darkest secret: " << this->contact[index].darkest_secret << std::endl;
		return 0;
	}
};