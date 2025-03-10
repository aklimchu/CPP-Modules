/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:03 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:04 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main (void){
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string& stringREF = string;
	
	std::cout << &string << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return 0;
}