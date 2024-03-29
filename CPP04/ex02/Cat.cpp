/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:17:55 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/06 11:54:25 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat const &src) : AAnimal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete(_brain);
}

Cat &Cat::operator=(Cat const &rhs) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &rhs)
	{
		*this->_brain = *rhs._brain;
		this->type = rhs.getType();
	}
	return *this;
}

void Cat::makeSound(void) const {
		std::cout << "Meow Meow" << std::endl;
}

std::string Cat::getIdeas(int index) const {
	if (index >= 100 || index < 0)
		return ("no idea for this index... :(");
	return this->_brain->getIdeas(index);
}

void Cat::setIdeas(std::string idea) {
	this->_brain->setIdeas(idea);
}
