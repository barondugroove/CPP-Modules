/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:41:06 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/25 17:30:44 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &rhs)
	{
		*this->_brain = *rhs._brain;
		this->type = rhs.getType();
	}
	return *this;
}

void WrongCat::makeSound(void) const {
		std::cout << "Weom Weom" << std::endl;
}
