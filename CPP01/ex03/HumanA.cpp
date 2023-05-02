/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/02 21:46:15 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon weaponType) {
	this->_name = name;
	this->_weapon = weaponType;
	return ;
}

HumanA::~HumanA(void) {
	return ;
}

void HumanA::attack(void) {
	std::cout << _name << "attacks with their " << _weapon.getType() << std::endl;
}
