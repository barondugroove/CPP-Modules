/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/22 15:57:24 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "CONSTRUCTOR MESSAGES :" << std::endl;
	ClapTrap clapTrap("ClapTrap");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3;
	clapTrap3 = clapTrap2;

	std::cout << std::endl;
	std::cout << "ACTIONS :" << std::endl;
	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(10);
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(4294967295);
	clapTrap.takeDamage(4294967295);
	std::cout << std::endl;

	std::cout << std::endl;
	clapTrap2.attack("the bad guys");
	std::cout << std::endl;

	std::cout << std::endl;
	clapTrap3.takeDamage(10);
	clapTrap3.attack("the brits");
	std::cout << std::endl;
	std::cout << "DESTRUCTOR MESSAGES :" << std::endl;
	return (0);
}
