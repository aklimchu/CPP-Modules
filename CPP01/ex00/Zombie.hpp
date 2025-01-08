#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>

class Zombie{
	public:
		Zombie(void);
		~Zombie(void);
		void announce( void );
		Zombie* newZombie( std::string name );
		void randomChump( std::string name );
	
	private:
		std::string name;
};

#endif