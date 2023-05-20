/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:17:55 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 20:21:40 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brains();
}

Dog::Dog(Dog const &src) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete (this->brain);
}

Dog &Dog::operator=(Dog const &rhs) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &rhs)
        *this = rhs;
    return *this;
}