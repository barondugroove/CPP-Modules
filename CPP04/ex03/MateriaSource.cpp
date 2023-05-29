/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:48:56 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 16:58:20 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : AMateria("Materia") {
	std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(std::string const &type) {
	std::cout << "MateriaSource parametric constructor called." << std::endl;
	this->type = type;
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource default destructor called." << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << "MateriaSource assignation operator called." << std::endl;
}
