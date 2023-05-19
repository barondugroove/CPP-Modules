/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/19 16:15:39 by bchabot          ###   ########.fr       */
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
	scavTrap.takeDamage(10);
	std::cout << "He now has " << scavTrap.getHitPoints() - 10 << " hit points and " << scavTrap.getEnergyPoints() - 1 << " energy points" << std::endl;
	scavTrap.beRepaired(10);
	std::cout << "He now has " << scavTrap.getHitPoints() << " hit points and " << scavTrap.getEnergyPoints() << " energy points" << std::endl;
	scavTrap.guardGate();
	std::cout << std::endl;
	return (0);
}
