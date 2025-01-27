# pragma once

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void filter( std::string level );
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};
