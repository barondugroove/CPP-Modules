/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:53:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 16:55:12 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void) {
	std::cout << "Character default constructor called." << std::endl;
}

Character::Character(std::string const &name) {
	std::cout << "Character parametric constructor called." << std::endl;
	this->_name = name;
}

Character::~Character(void) {
	std::cout << "Character default destructor called." << std::endl;
}

Character &Character::operator=(Character const &rhs) {
	std::cout << "Character assignation operator called." << std::endl;
}

void use(ICharacter &target) {
	std::cout << "* shoots an Character bolt at " << target.getName() << " *" << std::endl;
}
