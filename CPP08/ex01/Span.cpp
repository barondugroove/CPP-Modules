/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:35:28 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/06 13:43:24 by bchabot          ###   ########.fr       */
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
	}
	return *this;
}

template<typename T>
void Span::addNumbers(T iterBegin, T iterEnd) {
	T	iterCpy = iterBegin;
	for (; iterCpy != iterEnd; iterCpy++) {
		if (_array.size() == _size)
			break ;
		this->insert(iterBegin, iterCpy, iterEnd);
	}

}

void Span::addNumber(int nbr) {
	if (_array.size() == _size)
		std::cout << "PLEIN PLEIN" << std::endl;
	else
		_array.push_back(nbr);
}

int Span::shortestSpan() {
	if (_array.size() <= 1)
		std::cout << "PETIT PETIT" << std::endl;
	std::sort(_array.begin(), _array.end());
	int	shortSpan = _array[1] - _array[0];
	for (int i = 1; i < (int)_size - 1; i++)
		if (_array[i + 1] - _array[i] < shortSpan)
			shortSpan = _array[i + 1] - _array[i];
	return shortSpan;
}

int Span::longestSpan() {
	if (_array.size() <= 1)
		std::cout << "PETIT PETIT" << std::endl;
	std::sort(_array.begin(), _array.end());
	int	longSpan = _array.back() - _array.front();
	return longSpan;
}