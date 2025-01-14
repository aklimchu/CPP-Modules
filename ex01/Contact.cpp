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

int Contact::getIndex(void) const {
	return(this->index);
}

std::string Contact::getFirst(void) const {
	return(this->first_name);
}

std::string Contact::getLast(void) const {
	return(this->last_name);
}

std::string Contact::getNickname(void) const {
	return(this->nickname);
}

std::string Contact::getPhoneNumber(void) const {
	return(this->phone_number);
}

std::string Contact::getSecret(void) const {
	return(this->darkest_secret);
}