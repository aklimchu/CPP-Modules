/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:15:48 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 15:50:11 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int	array_elem = 10;
	AAnimal *AAnimals[array_elem];

	// Checking if we can instantiate base class AAnimal
	//AAnimal AAnimal;

    // Allocate memory for the AAnimals
	for (int i = 0; i < array_elem / 2; i++) {
		AAnimals[i] = new Dog();
	}
	for (int i = array_elem / 2; i < array_elem; i++) {
		AAnimals[i] = new Cat();
	}

	for (int i = 0; i < array_elem; i++) {
		AAnimals[i]->makeSound();
	}

    // Checking that the copies of a Dog or a Cat are not shallow
	Dog* original_dog = dynamic_cast<Dog*>(AAnimals[0]);
	original_dog->setDogIdeas(0, "Dogs rule the world");
	Dog copied_dog(*original_dog);
	original_dog->setDogIdeas(0, "Actually dogs are fun");
	std::cout << "original: " << original_dog->getDogIdeas(0) << std::endl << std::endl;
	std::cout << "copy: " << copied_dog.getDogIdeas(0) << std::endl << std::endl;


	// Deallocate memory for each AAnimal
	for (int i = 0; i < array_elem; i++) {
        delete AAnimals[i];
    }
	return 0;
}