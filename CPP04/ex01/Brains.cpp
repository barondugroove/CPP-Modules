/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brains.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:54:28 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 19:56:37 by bchabot          ###   ########.fr       */
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
        *this = rhs;
    return *this;
}