/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:17:55 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/25 17:06:47 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	_brain = new Brains();
}

Dog::Dog(Dog const &src) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete(_brain);
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
	{
		*this->_brain = *rhs._brain;
		this->type = rhs.getType();
	}
	return *this;
}

void Dog::makeSound(void) const {
		std::cout << "Bark Bark" << std::endl;
}

std::string Dog::getIdeas(int index) const {
	return this->_brain->getIdeas(index);
}

void Dog::setIdeas(std::string idea) {
	this->_brain->setIdeas(idea);
}