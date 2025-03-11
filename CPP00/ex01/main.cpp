#include "PhoneBook.hpp"
#include "Contact.hpp"

static int	check_digits(std::string string);
static void	check_input_str(std::string *string, std::string out_string);
static void	check_input_phone(std::string *string, std::string out_string);
static void	search_entry(PhoneBook	instance);

int	main() {
	PhoneBook	instance;
	std::string	input, first, last, nickname, phone, secret;

	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		input.clear();
		getline(std::cin, input);
		if (std::cin.fail())
		{
            std::cout << std::endl << "Invalid Input" << std::endl;
			return 1;
		}
		if (input.compare("ADD") == 0)
		{
			check_input_str(&first, "first name");
			check_input_str(&last, "last name");
			check_input_str(&nickname, "nickname");
			check_input_phone(&phone, "phone number");
			check_input_str(&secret, "darkest secret");
			instance.add_new_contact(first, last, nickname, phone, secret);
		}
		else if (input.compare("SEARCH") == 0)
			search_entry(instance);
		else if (input.compare("EXIT") == 0)
			exit (EXIT_SUCCESS);
	}
	return 0;
}

static int	check_digits(std::string string) {
	int length = string.length();
	for (int i = 0; i < length; i++){
		if (std::isdigit(string[i]) == 0)
		{
			std::cout << "The field can include only digits" << std::endl;
			return 1;
		}
	}
	return 0;
}

static void	check_input_str(std::string *string, std::string out_string) {
	string->clear();
	while (string->length() == 0)
	{
		std::cout << "Enter the " << out_string << ": ";
		getline(std::cin, *string);
		if (std::cin.fail())
		{
            std::cout << std::endl << "Invalid Input" << std::endl;
			return ;
		}
		else if (string->length() == 0)
			std::cout << "Field can't be empty" << std::endl;
	}
}

static void	check_input_phone(std::string *string, std::string out_string) {
	string->clear();
	while (string->length() == 0 || check_digits(*string) == 1)
	{
		std::cout << "Enter the " << out_string << ": ";
		getline(std::cin, *string);
		if (std::cin.fail())
		{
            std::cout << std::endl << "Invalid Input" << std::endl;
			return ;
		}
		else if (string->length() == 0)
			std::cout << "Field can't be empty" << std::endl;
	}
}

static void	search_entry(PhoneBook	instance) {
	std::string	entry_number;
	
	instance.print_all();
	std::cout << "Enter the entry number to be displayed: ";
	getline(std::cin, entry_number);
	if (std::cin.fail())
	{
       	std::cout << std::endl << "Invalid Input" << std::endl;
	}
	else if (!check_digits(entry_number)){
		try {
			instance.print_entry(std::stoi(entry_number) - 1);
		}
		catch (...) {
			std::cout << "Invalid Input" << std::endl;
		}
	}
}
