/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:29:07 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/02 16:04:12 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	std::cout << "MateriaSource copy constructor called." << std::endl;
	*this = src;
	return ;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << "MateriaSource assignation operator called." << std::endl;
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		delete inventory[i];
	return ;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break ;
		}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	else
		return 0;
}
