/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:18:30 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 18:55:56 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

class Point {
	public :
		Point(void);
		Point(Point const & src);
		~Point(void);

		Point & operator=(Point const & src);

	private :
		const Fixed x;
		const Fixed y;
};
