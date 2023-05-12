/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:05:04 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 15:06:45 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _AttackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _AttackDamage(0) {
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
        this->_AttackDamage = rhs._AttackDamage;
    }
    return (*this);
}

void ClapTrap::attack(std::string const & target) {
    std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->_name << " be repaired " << amount << " points of damage!" << std::endl;
}