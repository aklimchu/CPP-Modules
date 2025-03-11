/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:06:20 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/06 11:05:44 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char** argv)
{
	if (argc == 1)
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; ++i) {
		while (*argv[i]) {
			if (isupper(*argv[i]) == 0)
				std::cout << (char)toupper(*argv[i]);
			else
				std::cout << *argv[i];
			argv[i]++;
		}
	}
	std::cout << std::endl;
}
