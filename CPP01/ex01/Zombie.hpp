# pragma once

# include <iostream>

class Zombie{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void announce( void ) const;
		void setName(std::string name );
	
	private:
		std::string name;
};
