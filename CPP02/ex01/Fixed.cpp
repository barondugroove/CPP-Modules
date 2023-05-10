/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:30:24 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 12:33:35 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iomanip>

Fixed::Fixed(void) {
    std::cout << "Default constructor called." << std::endl;
    fixedPoint = 0;
    return ;
}

Fixed::Fixed(const int nbr) {
    std::cout << "Int constructor called." << std::endl;
    this->fixedPoint = nbr << this->bits;
    return ;
}

Fixed::Fixed(const float nbr) {
    std::cout << "Float constructor called." << std::endl;
    int fixedPoint = roundf((nbr * (1 << this->bits)));
    this->fixedPoint = fixedPoint;
    return ;
}

Fixed::Fixed(Fixed const & src) {
    std::cout << "Copy constructor called." << std::endl;
    *this = src;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called." << std::endl;
    return ;
}

int Fixed::getFixedPoint(void) const {
    return (this->fixedPoint);
}

int Fixed::getBits(void) const {
    return (this->bits);
}

Fixed & Fixed::operator=(Fixed const & src) {
    std::cout << "Copy assignment operator called." << std::endl;
    this->fixedPoint = src.fixedPoint;
    return (*this);
}

int Fixed::toInt(void) const {
    int originalInt = fixedPoint >> this->bits;
    return (originalInt);
}

float Fixed::toFloat(void) const {
    float originalFloat = (float)(fixedPoint) / (1 << this->bits);
    return (originalFloat);
}

std::ostream & operator<<(std::ostream & o, Fixed const & src) {
    o << src.toFloat();
    return o;
}
