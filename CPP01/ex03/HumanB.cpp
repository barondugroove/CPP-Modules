/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/02 21:45:41 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
	this->_name = name;
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void HumanB::attack(void) {
	std::cout << this->_name << "attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weaponType) {
	this->_weapon = weaponType;
}
