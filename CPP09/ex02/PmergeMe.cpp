/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/09 18:14:43 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>

PmergeMe::PmergeMe(char **av) {
	while (*av) {
		_s.push_back(atoi(*av));
		av++;
	}

	_size = _s.size();
	_straggler = -1;
	if (_size % 2 != 0)
		_straggler = _s.back();
}

PmergeMe::~PmergeMe() {
}

void	PmergeMe::createPairs(std::vector<std::pair<int, int> > &pairVector, std::vector<int> &s) {
	int x;
	int y;

	if (_size % 2 != 0)
		_straggler = s.back();
	for (std::vector<int>::iterator it = s.begin(); it != s.end() && (it + 1) != s.end(); it += 2) {
		x = *it;
		y = *(it + 1);
		if (x > y)
			std::swap(x, y);
		pairVector.push_back(std::make_pair(x, y));
	}
}

void	PmergeMe::sortPairs(std::vector<int> &_s) {
	std::vector<int> vectorMax;
	std::vector<std::pair<int, int> > vectorPair;
	int	size;

	size = _s.size();
	if (size < 2)
		return ;
	for (int i = 0; i < size - 1; i += 2) {
		if (_s[i] > _s[i + 1]) {
			vectorMax.push_back(_s[i]);
			vectorPair.push_back(std::make_pair(_s[i + 1], _s[i]));
		}
		else {
			vectorMax.push_back(_s[i + 1]);
			vectorPair.push_back(std::make_pair(_s[i], _s[i + 1]));
		}
	}
	sortPairs(vectorMax);

	_s.clear();
    for (size_t i = 0; i < vectorMax.size(); i++) {
		_s.push_back(vectorMax[i]);
	}
	
	for (size_t i = 0; i < vectorPair.size(); i++) {
		binarySearch(_s, vectorPair[i].first);
    }

	static int i = 0;
	std::cout << "Passage n* " << i++ << std::endl;
	std::cout << "VectorMax after recursion is : " << std::endl;
	for (std::vector<int>::iterator it = vectorMax.begin(); it != vectorMax.end(); it++) {
		std::cout << *it; 
		if (*(it + 1))
			std::cout << " - ";
	}
	
	std::cout << std::endl <<  "VectorPair after recursion is : " << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = vectorPair.begin(); it != vectorPair.end(); it++) {
		std::cout << it->first << " - " << it->second << " | ";
	}
	std::cout << std::endl;

}

void	PmergeMe::binarySearch(std::vector<int> &_s, int nbr) {

	int	idxMin = 0;
	int idxMax = _s.size();
	int middle = (idxMax - idxMin) / 2;;

	while ((idxMax - idxMin) > 1) {
		if (nbr > _s[middle]) {
			idxMin = middle;
			middle += (idxMax - idxMin) / 2;
		}
		else {
			idxMax = middle;
			middle -= (idxMax - idxMin) / 2;
		}
	}
	std::vector<int>::iterator it;
	if (nbr > _s[idxMin])
		it = _s.begin() + idxMax;
	else
		it = _s.begin() + idxMin;
	_s.insert(it, nbr);
}

int	PmergeMe::getJacobsthal(int n, int n1) {
	return (n + 2 * n1);
}

void	PmergeMe::FordJohnsonSort() {
	std::vector<std::pair<int, int> > pairVector;

	std::cout << "Vector before " << std::endl;
	for (std::vector<int>::iterator it = _s.begin(); it != _s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << "size is :" << _size << std::endl;
	std::cout << std::endl;
	std::cout << "_straggler is : " << _straggler << std::endl;
	std::cout << std::endl << std::endl;
	sortPairs(_s);
	if (_straggler != -1)
		binarySearch(_s, _straggler);
	std::cout  << "size is :" << _s.size() << std::endl;
	std::cout << std::endl << "Vector after " << std::endl;
	for (std::vector<int>::iterator it = _s.begin(); it != _s.end(); it++) {
		std::cout << *it << " ";
	}
}
