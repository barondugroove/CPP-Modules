/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:29:47 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 18:20:03 by bchabot          ###   ########.fr       */
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
		bool operator==(Fixed const & nbr) const;
		bool operator!=(Fixed const & nbr) const;
		bool operator<(Fixed const & nbr) const;
		bool operator<=(Fixed const & nbr) const;
		bool operator>(Fixed const & nbr) const;
		bool operator>=(Fixed const & nbr) const;

		Fixed operator*(Fixed const & nbr) const;
		Fixed operator/(Fixed const & nbr) const;
		Fixed operator+(Fixed const & nbr) const;
		Fixed operator-(Fixed const & nbr) const;

		Fixed & operator++(void);
		Fixed operator++(int nbr);
		Fixed & operator--(void);
		Fixed operator--(int nbr);

		static Fixed & min(Fixed & nbr1, Fixed & nbr2);
		static Fixed const & min(Fixed const & nbr1, Fixed const & nbr2);
		static Fixed & max(Fixed & nbr1, Fixed & nbr2);
		static Fixed const & max(Fixed const & nbr1, Fixed const & nbr2);

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
