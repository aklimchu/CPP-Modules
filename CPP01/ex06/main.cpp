/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:59 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:13:00 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(int argc, char **argv){
	if (argc < 2 || argc > 2)
		return 1;
	
	Harl instance;

	instance.filter(argv[1]);
	return 0;
}
