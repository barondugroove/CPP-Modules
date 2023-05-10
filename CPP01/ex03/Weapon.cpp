/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 14:59:19 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) {
	this->_type = type;
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

void Weapon::setType(std::string weaponType) {
	this->_type = weaponType;
}

const std::string& Weapon::getType(void) const {
	const std::string& copy = _type;
	return (copy);
}

