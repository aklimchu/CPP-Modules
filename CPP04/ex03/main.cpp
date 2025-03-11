/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:36 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 13:06:10 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << std::endl << "Testing the deep copy" << std::endl;
	Character copied_me(*me);
	copied_me.setName("copied_me");
	me->unequip(0);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	copied_me.equip(tmp1);
	
	std::cout << std::endl << std::endl;

	
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(3);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(10);


	Character* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	me->unequip(2);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}