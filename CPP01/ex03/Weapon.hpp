# pragma once

# include <iostream>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string& getType() const;
		void setType(std::string new_type);
	private:
		std::string type;
};