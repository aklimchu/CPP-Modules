/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:11:53 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:11:54 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>

class Zombie{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void announce( void ) const;
		void setName(std::string name );
	
	private:
		std::string name;
};
