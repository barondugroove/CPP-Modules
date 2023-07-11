/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:29:47 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/11 14:59:17 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <vector>
#include <algorithm>

class Span {
	public :
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		
		Span& operator=(const Span &rhs);

		void	addNumber(int nbr);
		template <typename T>
		void	addMultipleNumbers(T iterBeging, T iterEnd);
		int		shortestSpan();
		int		longestSpan();

	private :
		std::vector<int>	_array;
		unsigned int		_size;
};

#endif