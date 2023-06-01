/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:05:20 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/01 17:56:22 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) {
	std::cout << "Abstract Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
	std::cout << "Abstract Animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void) {
	std::cout << "Abstract Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
	std::cout << "Abstract Animal assignation operator called" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::string AAnimal::getType(void) const {
	return this->type;
}

void AAnimal::makeSound(void) const {
	std::cout << "Zit Zit" << std::endl;
}
