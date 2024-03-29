/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:47:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/11 12:44:09 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstddef>
#include <climits>

template<typename T>
Array<T>::Array() : _array(NULL) {
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	if (n > INT_MAX)
		throw Array<T>::IndexConstructorException();
	_array = new T[n]();
	_size = n;
}

template<typename T>
Array<T>::~Array() {
	delete[] _array;
}

template<typename T>
Array<T>::Array(const Array<T> &src) {
	if (this != &src) {
		this->_size = src.size();
		this->_array = new T[src.size()]();
		for (unsigned int i = 0; i < src._size; i++)
			this->_array[i] = src._array[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &rhs) {
	if (this != &rhs) {
		this->_size = rhs.size();
		delete [] this->_array;
		if (rhs._array == NULL)
		{
			this->_array = NULL;
			return *this;
		}
		this->_array = new T[rhs.size()]();
		for (unsigned int i = 0; i < rhs._size; i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](const unsigned int &index) const {
	if (_array == NULL || index >= _size)
		throw Array<T>::IndexErrorException();
	return (this->_array[index]);
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template<typename T>
void Array<T>::fillArray(T content, unsigned int index) {
	if (_array == NULL || index >= _size || index > INT_MAX)
		throw Array<T>::IndexErrorException();
	_array[index] = content; 
}

template<typename T>
const char* Array<T>::IndexErrorException::what() const throw() {
	return ("Index provided is not in array's size range.");
}

template<typename T>
const char* Array<T>::IndexConstructorException::what() const throw() {
	return ("Cannot create array class cause size provided is erroneous.");
}