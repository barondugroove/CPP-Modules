/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:05:04 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/22 16:02:04 by bchabot          ###   ########.fr       */
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
		std::cout << "ClapTrap " << this->_name << " is dead.💀" << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "ClapTrap " << this->_name << " has no energy left and can not attack.🔋" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
		std::cout << "ClapTrap " << this->_name << " lost 1 energy point and now has " << this->_energyPoints << " left" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead.💀" << std::endl;
	else
	{
		if ((long)this->_hitPoints - (long)amount <= 0)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
		if (this->_hitPoints <= 0)
			std::cout << "ClapTrap " << this->_name << " died from the attack.🪦" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " left." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is already dead and can not repair itself.💀" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no energy left and can not repair itself.🔋" << std::endl;
	else
	{
		if ((long)amount + (long)this->_hitPoints > 4294967295)
		{
			std::cout << "Amount repair error." << std::endl;
			return ;
		}
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " hit points." << std::endl;
	}
}

std::string &ClapTrap::getName(void) const {
    return ((std::string &)(this->_name));
}

int ClapTrap::getHitPoints(void) const {
    return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
}

void ClapTrap::setName(std::string name) {
    this->_name = name;
}

void ClapTrap::setHitPoints(int hitPoints) {
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
    this->_attackDamage = attackDamage;
}
