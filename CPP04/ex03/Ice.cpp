/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:17:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/31 16:43:18 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
	std::cout << "🧊 Ice default constructor called. 🧊" << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria(src) {
	std::cout << "🧊 Ice copy constructor called. 🧊" << std::endl;
	*this = src;
	return ;
}

Ice::~Ice(void) {
	std::cout << "🧊 Ice destructor called. 🧊" << std::endl;
}

Ice &Ice::operator=(Ice const &rhs) {
	std::cout << "🧊 Ice assignation operator called. 🧊" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

AMateria* Ice::clone(void) const {
	AMateria *tmp = new Ice();
	return tmp;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
