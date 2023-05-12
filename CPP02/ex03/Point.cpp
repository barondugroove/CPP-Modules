/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:18:09 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/11 17:45:18 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	return ;
}

Point::Point(Point const & src) : _x(src._x), _y(src._y) {
	return ;
}

Point::~Point(void) {
	return ;
}

Point & Point::operator=(Point const & src) {
    if (this != &src) {
        Point tmp(src._x.toFloat(), src._y.toFloat());
        *this = tmp;
    }
    return *this;
}

Point Point::operator-(Point const & src) const {
	float x = this->_x.toFloat() - src._x.toFloat();
	float y = this->_y.toFloat() - src._y.toFloat();
	return Point(x, y);
}

float Point::getX(void) const {
	return (this->_x.toFloat());
}

float Point::getY(void) const {
	return (this->_y.toFloat());
}