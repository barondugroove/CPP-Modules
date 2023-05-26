/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:39:27 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/25 11:49:31 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "Tiz Tiz" << std::endl;
}
