/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:34:44 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 16:40:51 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	{
		Fixed a( 42.42f );
		Fixed b( 42.11f );
		Fixed const c( 42.11f );
		Fixed const d( 10.01f );
		Fixed	e;

		if (a > b)
			std::cout << "a is higher than b" << std::endl;
		else
			std::cout << "b is lower than a" << std::endl;
		if (b < a)
			std::cout << "b is lower than a" << std::endl;
		else
			std::cout << "a is higher than b" << std::endl;
		if (b >= c)
			std::cout << "b is higher or equal than c" << std::endl;
		else
			std::cout << "b is lower than c" << std::endl;
		if (b <= c)
			std::cout << "b is lower or equal than c" << std::endl;
		else
			std::cout << "b is lower than c" << std::endl;
		if (b == c)
			std::cout << "b is equal to c" << std::endl;
		else
			std::cout << "b is not equal to c" << std::endl;
		if (b != c)
			std::cout << "b is not equal to c" << std::endl;
		else
			std::cout << "b is equal to c" << std::endl;


		std::cout << "b + c = " << b + c << std::endl;
		std::cout << "a - c = " << a - c << std::endl;
		std::cout << "a * c = " << a * c << std::endl;
		std::cout << "a / d = " << a / d << std::endl;

		std::cout << std::endl;

		std::cout << "e = " << e << std::endl;
		std::cout << "++e = " << ++e << std::endl;
		std::cout << "e = " << e << std::endl;
		std::cout << "e++ = " << e++ << std::endl;
		std::cout << "e = " << e << std::endl;

		std::cout << std::endl;

		std::cout << "--e = " << --e << std::endl;
		std::cout << "e = " << e << std::endl;
		std::cout << "e-- = " << e-- << std::endl;
		std::cout << "e = " << e << std::endl;

		std::cout << std::endl;

		std::cout << "smallest Fixed is = " << Fixed::min(a, b) << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "smallest Fixed is = " << Fixed::min(c, d) << std::endl;

		std::cout << std::endl;

		std::cout << "max Fixed is = " << Fixed::max(a, b) << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "max Fixed is = " << Fixed::max(c, d) << std::endl;
		return (0);
	}
}
