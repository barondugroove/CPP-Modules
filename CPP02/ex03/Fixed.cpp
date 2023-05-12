/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:30:24 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/11 15:11:14 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iomanip>

Fixed::Fixed(void) {
	fixedPoint = 0;
	return ;
}

Fixed::Fixed(const int nbr) {
	this->fixedPoint = nbr << this->bits;
	return ;
}

Fixed::Fixed(const float nbr) {
	int fixedPoint = (int)(roundf(nbr * (1 << this->bits)));
	this->fixedPoint = fixedPoint;
	return ;
	}

Fixed::~Fixed(void) {
	return ;
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
	return ;
}

Fixed & Fixed::operator=(Fixed const & src) {
	this->fixedPoint = src.getFixedPoint();
	return (*this);
}

int Fixed::getFixedPoint(void) const {
	return (this->fixedPoint);
}

int Fixed::getBits(void) const {
	return (this->bits);
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

bool Fixed::operator==(Fixed const & nbr) const {
	if (this->toFloat() == nbr.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const & nbr) const {
	if (this->toFloat() != nbr.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>(Fixed const & nbr) const {
	if (this->toFloat() > nbr.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const & nbr) const {
	if (this->toFloat() >= nbr.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const & nbr) const {
	if (this->toFloat() < nbr.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const & nbr) const {
	if (this->toFloat() <= nbr.toFloat())
		return (true);
	return (false);
}

Fixed Fixed::operator*(Fixed const & nbr) const {
	return Fixed(this->toFloat() * nbr.toFloat());
}

Fixed Fixed::operator/(Fixed const & nbr) const {
	return Fixed(this->toFloat() / nbr.toFloat());
}

Fixed Fixed::operator+(Fixed const & nbr) const {
	return Fixed(this->toFloat() + nbr.toFloat());
}

Fixed Fixed::operator-(Fixed const & nbr) const {
	return Fixed(this->toFloat() - nbr.toFloat());
}

Fixed & Fixed::operator++(void) {
	this->fixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed & Fixed::operator--(void) {
	this->fixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

Fixed const & Fixed::min(Fixed const & nbr1, Fixed const & nbr2) {
	if (nbr1 < nbr2)
		return (nbr1);
	else
		return (nbr2);
}

Fixed & Fixed::min(Fixed & nbr1, Fixed & nbr2) {
	if (nbr1 < nbr2)
		return (nbr1);
	else
		return (nbr2);
}

Fixed const & Fixed::max(Fixed const & nbr1, Fixed const & nbr2) {
	if (nbr1 > nbr2)
		return (nbr1);
	else
		return (nbr2);
}

Fixed & Fixed::max(Fixed & nbr1, Fixed & nbr2) {
	if (nbr1 > nbr2)
		return (nbr1);
	else
		return (nbr2);
}
