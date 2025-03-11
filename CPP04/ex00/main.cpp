/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:15:48 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 14:17:13 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	
	std::cout << cat->getType() << " " << std::endl;
 	cat->makeSound(); //will output the cat sound!
	
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;
	
	//-------------wrong animal/cat-----------------//
	
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	
	std::cout << wrong_cat->getType() << " " << std::endl;
 	wrong_cat->makeSound(); //will output the wrong_animal sound!

	std::cout << wrong_meta->getType() << " " << std::endl;
	wrong_meta->makeSound();

	delete wrong_meta;
	delete wrong_cat;

return 0;
}