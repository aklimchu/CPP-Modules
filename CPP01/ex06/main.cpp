# include "Harl.hpp"

int main(int argc, char **argv){
	if (argc < 2 || argc > 2)
		return 1;
	
	Harl instance;

	instance.filter(argv[1]);
	return 0;
}
