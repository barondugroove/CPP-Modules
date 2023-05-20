/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/20 17:56:05 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void) {
	FragTrap fragTrap("FragTrap");
	FragTrap fragTrap2(fragTrap);
	FragTrap fragTrap3;
	fragTrap3 = fragTrap2;

	std::cout << std::endl;
	fragTrap.highFivesGuys();
	fragTrap.attack("target");
	fragTrap.takeDamage(fragTrap.getAttackDamage());
	fragTrap.beRepaired(10);
	for (int i = 0; i < 3; i++)
		fragTrap.takeDamage(fragTrap.getAttackDamage());
	fragTrap.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
