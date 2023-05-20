/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/20 17:46:02 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	ScavTrap scavTrap("ScavTrap");
	ScavTrap scavTrap2(scavTrap);
	ScavTrap scavTrap3;
	scavTrap3 = scavTrap2;

	std::cout << std::endl;
	scavTrap.attack("target");
	scavTrap.guardGate();
	for (int i = 0; i < 3; i++)
		scavTrap.takeDamage(scavTrap.getAttackDamage());
	scavTrap.beRepaired(10);
	scavTrap.takeDamage(scavTrap.getAttackDamage());
	scavTrap.takeDamage(scavTrap.getAttackDamage());
	std::cout << std::endl;
	return (0);
}
