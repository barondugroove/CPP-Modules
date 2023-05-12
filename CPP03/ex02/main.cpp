/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 17:14:28 by bchabot          ###   ########.fr       */
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

	fragTrap.attack("target");
	fragTrap.takeDamage(10);
	std::cout << "He now has " << fragTrap.getHitPoints() - 10 << " hit points and " << fragTrap.getEnergyPoints() - 1 << " energy points" << std::endl;
	fragTrap.beRepaired(10);
	std::cout << "He now has " << fragTrap.getHitPoints() << " hit points and " << fragTrap.getEnergyPoints() << " energy points" << std::endl;
	fragTrap.highFivesGuys();
	return (0);
}
