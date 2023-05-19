/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:05:04 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/19 16:13:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const & target) {
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead. 💀" << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "ClapTrap " << this->_name << " has no energy left and can not attack. 🔋" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
		std::cout << "ClapTrap " << this->_name << " lost 1 energy point and now has " << this->_energyPoints << " left" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead. 💀" << std::endl;
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
		if (this->_hitPoints <= 0)
			std::cout << "ClapTrap " << this->_name << " died from the attack. 🪦" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " left." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead and can not repair itself. 💀" << std::endl;
	else
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " left." << std::endl;
	}
}
