/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:59 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/22 16:09:30 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->updateStats();
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Parametric constructor called" << std::endl;
	this->updateStats();
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called" << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->setName(rhs.getName());
		this->setAttackDamage(rhs.getAttackDamage());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setHitPoints(rhs.getHitPoints());
	}
	return (*this);
}

void ScavTrap::attack(std::string const & target) {
	if (this->getHitPoints() <= 0)
		std::cout << "ScavTrap " << this->getName() << " is dead. 💀" << std::endl;
	else if (this->getEnergyPoints() < 1)
		std::cout << "ScavTrap " << this->getName() << " has no energy left and can not attack. 🔋" << std::endl;
	else
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "ScavTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage !" << std::endl;
		std::cout << "ScavTrap " << this->getName() << " lost 1 energy point and now has " << this->getEnergyPoints() << " left." << std::endl;
	}
	return;
}

void ScavTrap::guardGate(void) {
	if (this->getHitPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " is dead and can not guard the gate. 💀" << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " has enterred Gate keeper mode." << std::endl;
	return;
}

void ScavTrap::updateStats(void) {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return;
}
