/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 14:57:06 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
	return ;
}

Zombie::~Zombie(void) {
	std::cout << "I love my family. Potato, potato, potato. " << "F for " << this->_name << std::endl;
	return ;
}

void Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}
