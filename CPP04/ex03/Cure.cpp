/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:00:53 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 16:14:08 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure default constructor called." << std::endl;
	return ;
}

Cure::Cure(std::string const &type) {
	std::cout << "Cure parametric constructor called" << std::endl;
	return ;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure &Cure::operator=(Cure const &rhs) {
	*this = rhs;
}

void use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wound *" << std::endl;
}
