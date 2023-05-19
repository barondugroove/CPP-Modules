/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:18:30 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/17 16:29:16 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

class Point {
	public :
		Point(void);
		Point(const float x, const float y);
		Point(Point const & src);
		~Point(void);

		Point & operator=(Point const & src);
		Point operator-(Point const & nbr) const;

		float getX(void) const;
		float getY(void) const;

	private :
		const Fixed _x;
		const Fixed _y;
};
