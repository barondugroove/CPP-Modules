/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:59:53 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 16:13:11 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(std::string const &type) {
	std::cout << "Ice parametric constructor called." << std::endl;
	this->type = type;
}

Ice::~Ice(void) {
	std::cout << "Ice default destructor called." << std::endl;
}

Ice &Ice::operator=(Ice const &rhs) {
	std::cout << "Ice assignation operator called." << std::endl;
}

void use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
