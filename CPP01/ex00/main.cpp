/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:11:27 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:11:28 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main(void)
{
	Zombie* Zombie = newZombie("ZombieOne");
    Zombie->announce();
    delete Zombie;
	
	randomChump("ZombieTwo");
	return 0;
}