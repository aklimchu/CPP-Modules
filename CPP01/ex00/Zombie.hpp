/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:11:42 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:11:43 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>

class Zombie{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce( void ) const;
	
	private:
		std::string name;
};
