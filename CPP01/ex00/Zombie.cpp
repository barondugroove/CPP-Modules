/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/02 19:26:16 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {
	this->_name = name;
	return ;
}

Zombie::~Zombie(void) {
	std::cout << "I love my family. Potato, potato, potato. " << "F for " << this->_name << std::endl;
	return ;
}

void Zombie::announce(void) const {
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}