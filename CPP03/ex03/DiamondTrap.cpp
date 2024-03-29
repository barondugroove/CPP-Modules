/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:30:50 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/22 18:17:01 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap() {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = name + "_clap_name";
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(), FragTrap(), ScavTrap() {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = src;
	return;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called" << std::endl;
	return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		FragTrap::setHitPoints(FragTrap::getHitPoints());
		ScavTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
		FragTrap::setAttackDamage(FragTrap::getAttackDamage());
	}
	return (*this);
}

void DiamondTrap::whoAmI(void) {
	if (this->getHitPoints() <= 0)
		std::cout << this->_name << " is dead and can not talk.💀" << std::endl;
	else
		std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->getName() << std::endl;
}
