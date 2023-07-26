/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:35:28 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/26 15:18:57 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span() : _array(0) {
	_size = 0;
}

Span::Span(unsigned int N) {
	std::vector<int> _array (N, 0);
	_size = N;
}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {
}

Span& Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		if (!_array.empty())
			_array.clear();
		this->_array = rhs._array;
		this->_size = rhs._size;
	}
	return *this;
}

void	Span::addMultipleNumbers(std::list<int>::iterator iterBegin, std::list<int>::iterator iterEnd) {
	if (_array.size() == _size)
		throw arrayFull();
	_array.insert(this->_array.begin(), iterBegin, iterEnd);
}

void Span::addNumber(int nbr) {
	if (_array.size() == _size)
		throw arrayFull();
	_array.push_back(nbr);
}

int Span::shortestSpan() {
	if (_array.size() <= 1)
		throw arrayEmpty();

	std::sort(_array.begin(), _array.end());

	int	shortSpan = _array[1] - _array[0];
	for (int i = 1; i < (int)_size - 1; i++) {
		if (_array[i + 1] - _array[i] < shortSpan)
			shortSpan = _array[i + 1] - _array[i];
	}
	return shortSpan;
}

int Span::longestSpan() {
	if (_array.size() <= 1)
		throw arrayEmpty();
	std::sort(_array.begin(), _array.end());
	int	longSpan = _array.back() - _array.front();
	return longSpan;
}

const char* Span::arrayFull::what() const throw() {
	return ("Can't add value to array cause it is full.");
}

const char* Span::arrayEmpty::what() const throw() {
	return ("Can't calculate value cause array is empty or contains only one element.");
}
