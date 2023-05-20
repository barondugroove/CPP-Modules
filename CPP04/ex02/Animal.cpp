/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:05:20 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 19:33:53 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &rhs)
        *this = rhs;
    return *this;
}

std::string Animal::getType(void) const {
    return this->type;
}

void Animal::makeSound(void) const {
    if (getType() == "Dog")
        std::cout << "Bark Bark" << std::endl;
    else
        std::cout << "Meow Meow" << std::endl;
}