/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/22 16:12:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "CONSTRUCTOR MESSAGES :" << std::endl;
	FragTrap fragTrap("FragTrap");
	FragTrap fragTrap2(fragTrap);
	FragTrap fragTrap3;
	fragTrap3 = fragTrap2;

	std::cout << "ACTIONS :" << std::endl;
	std::cout << std::endl;
	fragTrap.highFivesGuys();
	fragTrap.attack("target");
	fragTrap.beRepaired(10);
	for (int i = 0; i < 4; i++)
		fragTrap.takeDamage(fragTrap.getAttackDamage());
	fragTrap.highFivesGuys();
	std::cout << std::endl;
	std::cout << "DESTRUCTOR MESSAGES :" << std::endl;
	return (0);
}
