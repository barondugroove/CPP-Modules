/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:47:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/04 18:55:02 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
	public :
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(const Array<T> &src);
		~Array<T>();

		Array<T>& operator=(const Array<T> &rhs);
		T& operator[](const unsigned int &index) const;

		class IndexErrorException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		class IndexConstructorException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		unsigned int	size() const;
		void			fillArray(T content, unsigned int index);

	private :
		T*				_array;
		unsigned int	_size;
};

#endif