/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:59:08 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 18:25:32 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    this->updateStats();
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap constructor called" << std::endl;
    this->updateStats();
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = src;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &rhs) {
        this->setName(rhs.getName());
        this->setAttackDamage(rhs.getAttackDamage());
        this->setEnergyPoints(rhs.getEnergyPoints());
        this->setHitPoints(rhs.getHitPoints());
    }
    return (*this);
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << " is asking for high fives" << std::endl;
}

void FragTrap::updateStats(void) {
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}