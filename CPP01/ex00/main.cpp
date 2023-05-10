/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:38:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 15:42:21 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main(void)
{
	Zombie *zombie1;
	Zombie *zombie2;

	zombie1 = newZombie("Ed");
	zombie1->announce();
	delete(zombie1);
	randomChump("Herzog");
	zombie2 = newZombie("Jason Voorhees");
	zombie2->announce();
	delete(zombie2);
	randomChump("Solomon Grundy");
}
