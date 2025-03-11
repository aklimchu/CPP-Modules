/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:56 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:57 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void filter( std::string level );
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};
