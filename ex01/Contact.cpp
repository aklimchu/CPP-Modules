#include "Contact.hpp"

Contact::Contact() {
}

Contact::Contact(int i, std::string first, std::string last, std::string nick,
			std::string phone, std::string secret) {
	this->index = i;
	this->first_name = first;
	this->last_name = last;
	this->nickname = nick;
	this->phone_number = phone;
	this->darkest_secret = secret;
}

Contact::~Contact() {
	return ;
}

std::string Contact::getField(int field) const {
	std::string	index_str;
	
	switch (field) {
		case 0:
		index_str = std::to_string(this->index);
		return(index_str);
		case 1:
		return(this->first_name);
		break ;
		case 2:
		return(this->last_name);
		break ;
		case 3:
		return(this->nickname);
		break ;
		case 4:
		return(this->phone_number);
		break ;
		case 5:
		return(this->darkest_secret);
		break ;
		default:
		std::cout << "No field found" << std::endl;
	}
	return (nullptr);
}
