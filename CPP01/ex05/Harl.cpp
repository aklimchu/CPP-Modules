#include "Harl.hpp"

Harl::Harl() {
};

Harl::~Harl() {
};

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
};

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
};

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ";
	std::cout << "years whereas you started working here since last month." << std::endl << std::endl;
};

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
};

void Harl::complain( std::string level ) {
	void (Harl::*complaints[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            (this->*complaints[i])();
            return;
        }
    }
    std::cout << "Harl doesn't have any comment for this level." << std::endl << std::endl;
};