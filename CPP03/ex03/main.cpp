/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 18:50:18 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
	DiamondTrap diamondTrap("DiamondTrap");
	DiamondTrap diamondTrap2(diamondTrap);
	DiamondTrap diamondTrap3;
	diamondTrap3 = diamondTrap2;

	std::cout << std::endl;
	diamondTrap.attack("target");
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(10);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.attack("target");
	diamondTrap.whoAmI();
	std::cout << std::endl;
	return (0);
}
