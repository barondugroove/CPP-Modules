/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:34:44 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/11 17:57:13 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	{
		Point a = Point(0, 0);
		Point b = Point(4, 0);
		Point c = Point(2, 4);
		Point point = Point(2, 1);
		if (bsp(a, b, c, point) == true)
			std::cout << "Point is in the triangle" << std::endl;
		else
			std::cout << "Point is not in the triangle" << std::endl;
	}
	{
		Point a = Point(0, 0);
		Point b = Point(10, 30);
		Point c = Point(20, 0);
		Point point = Point(2, 3);
		if (bsp(a, b, c, point) == true)
			std::cout << "Point is in the triangle" << std::endl;
		else
			std::cout << "Point is not in the triangle" << std::endl;
	}			
	return 0;
}
