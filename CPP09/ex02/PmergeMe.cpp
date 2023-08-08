/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/08 18:41:40 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

PmergeMe::PmergeMe(char **av) {
	while (*++av)
		_s.push_back(atoi(*av));
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

	int idx = 0;
    for (int i = 0; i < size - 1; i++) {
        _s[i] = vectorMax[idx];
		idx++;
    }

	static int i = 0;
	std::cout << "Passage n* " << i++ << std::endl;
	std::cout << "VectorMax is : " << std::endl;
	for (std::vector<int>::iterator it = vectorMax.begin(); it != vectorMax.end(); it++) {
		std::cout << *it << " - ";
	}
/*	std::cout << std::endl <<  "VectorPair is : " << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = vectorPair.begin(); it != vectorPair.end(); it++) {
		std::cout << it->first << " - " << it->second << " | ";
	}*/
	std::cout << std::endl;

}

/*
void PmergeMe::mergePairs(std::vector<std::pair<int, int> > &resultVector, std::vector<std::pair<int, int> > &vector1, std::vector<std::pair<int, int> > &vector2) {
	int i = 0;
	int j = 0;
	int size1 = vector1.size();
	int size2 = vector2.size();

	resultVector.clear(); // Clear the result vector before merging
	std::cout << "Vector1 " << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = vector1.begin(); it != vector1.end(); it++) {
		std::cout << it->first << " - " << it->second  << " / ";
	}
	std::cout << std::endl;
	std::cout << "Vector2 " << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = vector2.begin(); it != vector2.end(); it++) {
		std::cout << it->first << " - " << it->second  << " / ";
	}
	std::cout << std::endl;

	while (i < size1 && j < size2) {
			if (vector1[i].second <= vector2[j].second) {
				resultVector.push_back(vector1[i]);
				i++;
			}
			else {
				resultVector.push_back(vector2[j]);
				j++;
			}
	}

	// Append any remaining elements from vector1 and vector2 to resultVector
	while (i < size1) {
		resultVector.push_back(vector1[i]);
		i++;
	}

	while (j < size2) {
		resultVector.push_back(vector2[j]);
		j++;
	}
	std::cout << "Result after " << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = resultVector.begin(); it != resultVector.end(); it++) {
		std::cout << it->first << " - " << it->second  << " / ";
	}
	std::cout << std::endl << std::endl;
}
*/

void	PmergeMe::FordJohnsonSort() {
	std::vector<std::pair<int, int> > pairVector;

	std::cout << "Vector before " << std::endl;
	for (std::vector<int>::iterator it = _s.begin(); it != _s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "_straggler is : " << _straggler << std::endl;
	std::cout << std::endl << std::endl;
	sortPairs(_s);
	std::cout << std::endl << "Vector after " << std::endl;
	for (std::vector<int>::iterator it = _s.begin(); it != _s.end(); it++) {
		std::cout << *it << " ";
	}
}
