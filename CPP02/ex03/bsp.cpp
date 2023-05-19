/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:30:29 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/17 16:38:15 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

float cross_product(Point p1, Point p2, Point p3) {
	float ux = p2.getX() - p1.getX();
	float uy = p2.getY() - p1.getY();
	float vx = p3.getX() - p1.getX();
	float vy = p3.getY() - p1.getY();
	return ux * vy - uy * vx;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	if (cross_product(a, b, point) > 0 && cross_product(b, c, point) > 0 && cross_product(c, a, point) > 0) {
		return (true);
	}
	if (cross_product(a, b, point) < 0 && cross_product(b, c, point) < 0 && cross_product(c, a, point) < 0) {
		return (true);
	}
	return (false);
}
