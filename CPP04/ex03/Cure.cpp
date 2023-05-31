/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:17:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/31 17:04:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	std::cout << "🩹 Cure default constructor called. 🩹" << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src) {
	std::cout << "🩹 Cure copy constructor called. 🩹" << std::endl;
	*this = src;
	return ;
}

Cure::~Cure(void) {
	std::cout << "🩹 Cure destructor called. 🩹" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs) {
	std::cout << "🩹 Cure assignation operator called. 🩹" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

AMateria* Cure::clone(void) const {
	AMateria *tmp = new Cure();
	return tmp;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}

