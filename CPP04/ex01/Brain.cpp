/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:54:28 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/06 11:50:24 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}

std::string Brain::getIdeas(int index) const {
	if (index >= 100 || index < 0)
		return ("no idea for this index... :(");
	return (this->ideas[index]);
}

void Brain::setIdeas(std::string idea) {
	for (int i = 0; i < 100; i++)
		if (ideas[i].empty())
		{
			ideas[i] = idea;
			break ;
		}
}
