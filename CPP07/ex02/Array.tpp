/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:47:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/03 18:45:13 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstddef>

template<typename T>
Array<T>::Array() : _array(NULL) {
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	_array = new T[n];
	_size = n;
}

template<typename T>
Array<T>::~Array() {
}

template<typename T>
Array<T>::Array(const Array<T> &src) {
	*this = src;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &rhs) {
	if (this != &rhs) {
		delete this->_array;
		if (rhs._array == NULL)
			this->_array = NULL;
		unsigned int nbr = rhs.size();
		this->_array = new T[nbr];
		for (unsigned int i = 0; i < nbr; i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](const unsigned int &index) const {
	if (!this->_array[index])
		std::cout << "Bad index." << std::endl;
}

template<typename T>
const char* Array<T>::IndexErrorException::what() const throw() {
	return ("This index does not exist.");
}

template<typename T>
const char* Array<T>::NoContentErrorException::what() const throw() {
	return ("No content at the index provided.");
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template<typename T>
void Array<T>::fillArray(T content, unsigned int index) {
	if (!_array || index >= _size)
		throw IndexErrorException();
	if (_array[index] == 5)
		throw NoContentErrorException();
	_array[index] = content; 
}


