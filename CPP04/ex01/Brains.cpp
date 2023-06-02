/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brains.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:54:28 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/02 16:19:54 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brains.hpp"
#include <iostream>

Brains::Brains(void) {
	std::cout << "Brains default constructor called" << std::endl;
}

Brains::Brains(Brains const &src) {
	std::cout << "Brains copy constructor called" << std::endl;
	*this = src;
}

Brains::~Brains(void) {
	std::cout << "Brains destructor called" << std::endl;
}

Brains &Brains::operator=(Brains const &rhs) {
	std::cout << "Brains assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}

std::string Brains::getIdeas(int index) const {
	if (index >= 100 || index < 0)
		return ("no idea for this index... :(");
	return (this->ideas[index]);
}

void Brains::setIdeas(std::string idea) {
	for (int i = 0; i < 100; i++)
		if (ideas[i].empty())
		{
			ideas[i] = idea;
			break ;
		}
}
