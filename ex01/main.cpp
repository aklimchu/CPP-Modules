#include "PhoneBook.hpp"
#include "Contact.hpp"

int	check_digits(std::string string)
{
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

int	main(){
	PhoneBook	instance;
	std::string	input;
	std::string	first;
	std::string	last;
	std::string	nickname;
	std::string	phone;
	std::string	secret;
	std::string	entry_number;

	while (1)
	{
		std::cout << "Enter the request: ";
		input.clear();
		getline(std::cin, input);
		if (std::cin.fail())
		{
            std::cout << std::endl << "Invalid Input" << std::endl;
			return 1;
		}
		if (input.compare("ADD") == 0)
		{
			first.clear();
			while (first.length() == 0)
			{
				std::cout << "Enter the first name: ";
				getline(std::cin, first);
				if (std::cin.fail())
				{
                    std::cout << std::endl << "Invalid Input" << std::endl;
					return 1;
				}
				else if (first.length() == 0)
					std::cout << "Field can't be empty" << std::endl;
			}
			last.clear();
			while (last.length() == 0)
			{
				std::cout << "Enter the last name: ";
				getline(std::cin, last);
				if (std::cin.fail())
				{
                    std::cout << std::endl << "Invalid Input" << std::endl;
					return 1;
				}
				if (last.length() == 0)
					std::cout << "Field can't be empty" << std::endl;
			}
			nickname.clear();
			while (nickname.length() == 0)
			{
				std::cout << "Enter the nickname: ";
				getline(std::cin, nickname);
				if (std::cin.fail())
				{
                    std::cout << std::endl << "Invalid Input" << std::endl;
					return 1;
				}
				if (nickname.length() == 0)
					std::cout << "Field can't be empty" << std::endl;
			}
			phone.clear();
			while (phone.length() == 0 || check_digits(phone) == 1)
			{
				std::cout << "Enter the phone number: ";
				getline(std::cin, phone);
				if (std::cin.fail())
				{
                    std::cout << std::endl << "Invalid Input" << std::endl;
					return 1;
				}
				if (phone.length() == 0)
					std::cout << "Field can't be empty" << std::endl;
			}
			secret.clear();
			while (secret.length() == 0)
			{
				std::cout << "Enter the darkest secret: ";
				getline(std::cin, secret);
				if (std::cin.fail())
				{
                    std::cout << std::endl << "Invalid Input" << std::endl;
					return 1;
				}
				if (secret.length() == 0)
					std::cout << "Field can't be empty" << std::endl;
			}
			instance.add_new_contact(first, last, nickname, phone, secret);

		}
		else if (input.compare("SEARCH") == 0)
		{
			instance.print_all();
			int print_entry_return = 1;
			while (print_entry_return){
				std::cout << "Enter the entry number to be displayed: ";
				getline(std::cin, entry_number);
				if (std::cin.fail())
				{
                    std::cout << std::endl << "Invalid Input" << std::endl;
					return 1;
				}
				if (!check_digits(entry_number)){
					try {
					print_entry_return = instance.print_entry(std::stoi(entry_number) - 1);
					}
					catch (...) {
						std::cout << "Invalid Input" << std::endl;
						return 1;
					}
				}
			}
		}
		else if (input.compare("EXIT") == 0)
			exit (EXIT_SUCCESS);
	}
	return 0;
}