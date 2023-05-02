/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:38:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/02 21:56:09 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde( int N, std::string name );

int	main(int ac, char **av)
{
	Zombie *hord;
	Zombie *worldWarZ;

	hord = zombieHorde(10, "Jason Voorhees");
	for (int i = 0; i < 10; i++)
		hord[i].announce();
	delete[](hord);
	worldWarZ = zombieHorde(10, "Tom Cruise");
	for (int i = 0; i < 10; i++)
		worldWarZ[i].announce();
	delete[](worldWarZ);
}
