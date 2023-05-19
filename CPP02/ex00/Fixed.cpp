/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:30:24 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/17 12:33:04 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called." << std::endl;
	fixedPoint = 0;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called." << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & src) {
	std::cout << "Copy assignment operator called." << std::endl;
	this->fixedPoint = src.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called." << std::endl;
	return (this->fixedPoint);
}

void Fixed::setRawbits(int const raw) {
	this->fixedPoint = raw;
}
