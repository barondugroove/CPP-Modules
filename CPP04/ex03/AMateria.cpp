/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:04:07 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/31 16:01:20 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void) {
	std::cout << "AMateria default constructor called." << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type) {
	std::cout << "AMateria parametric constructor called." << std::endl;
	this->type = type;
	return ;
}

AMateria::AMateria(AMateria const &src) {
	std::cout << "AMateria copy constructor called." << std::endl;
	*this = src;
	return ;
}

AMateria &AMateria::operator=(AMateria const &rhs) {
	std::cout << "AMateria assignation operator called." << std::endl;
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

std::string const & AMateria::getType(void) const {
	return (this->type);
}

void AMateria::use(ICharacter &target) {
	(void)target;
	return ;
}
