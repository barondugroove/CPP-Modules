/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:29:47 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/17 12:22:32 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <exception>

class Span {
	public :
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		
		Span& operator=(const Span &rhs);

		void	addNumber(int nbr);
		void	addMultipleNumbers(std::list<int>::iterator iterBegin, std::list<int>::iterator iterEnd);
		int		shortestSpan();
		int		longestSpan();

		class arrayFull : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		class arrayEmpty : public std::exception {
			public :
				virtual const char* what() const throw();
		};

	private :
		std::vector<int>	_array;
		unsigned int		_size;
};

#endif