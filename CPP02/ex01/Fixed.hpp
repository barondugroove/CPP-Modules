/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:29:47 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/17 16:02:35 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
	public :
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const & src);
		int		getFixedPoint(void) const;
		int		getBits(void) const;
		void	setRawbits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private :
		int fixedPoint;
		static const int bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & nbr);
