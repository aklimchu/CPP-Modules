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
	this->contact[i] = Contact(i + 1, first, last, nickname, phone, secret);
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
		index_str = std::to_string(this->contact[i].getIndex());
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
		word_length = this->contact[i].getFirst().length();
		if (word_length > 10)
		{
			short_str = this->contact[i].getFirst().substr(0, 9);
			short_str.push_back('.');
		}
		else
			short_str = this->contact[i].getFirst();
		std::cout << "|" << std::setw(10) << short_str;

		short_str.clear();
		word_length = this->contact[i].getLast().length();
		if (word_length > 10)
		{
			short_str = this->contact[i].getLast().substr(0, 9);
			short_str.push_back('.');
		}
		else
			short_str = this->contact[i].getLast();
		std::cout << "|" << std::setw(10) << short_str;

		short_str.clear();
		word_length = this->contact[i].getNickname().length();
		if (word_length > 10)
		{
			short_str = this->contact[i].getNickname().substr(0, 9);
			short_str.push_back('.');
		}
		else
			short_str = this->contact[i].getNickname();
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
		std::cout << "Index: " << this->contact[index].getIndex() << std::endl;
		std::cout << "First name: " << this->contact[index].getFirst() << std::endl;
		std::cout << "Last name: " << this->contact[index].getLast() << std::endl;
		std::cout << "Nickname: " << this->contact[index].getNickname() << std::endl;
		std::cout << "Phone number: " << this->contact[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->contact[index].getSecret() << std::endl;
		return 0;
	}
};