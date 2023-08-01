/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/01 19:09:00 by bchabot          ###   ########.fr       */
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
		pairVector.push_back(std::pair<int, int>(x, y));
	}
}

void	PmergeMe::sortPairs(std::vector<std::pair<int, int> > &pairVector) {
	std::vector<std::pair<int, int> > vector1;
	std::vector<std::pair<int, int> > vector2;
	int	size;

	size = pairVector.size();
	if (size < 2)
		return ;
	for (int i = 0; i < size; i++) {
			if (i < size / 2)
				vector1.push_back(pairVector[i]);
			else
				vector2.push_back(pairVector[i]);
	}

	sortPairs(vector1);
	sortPairs(vector2);

	mergePairs(pairVector, vector1, vector2);
}

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

void	PmergeMe::FordJohnsonSort() {
	std::vector<std::pair<int, int> > pairVector;

	createPairs(pairVector, _s);
	std::cout << "_straggler is : " << _straggler << std::endl;
	std::cout << "Vector before " << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++) {
		std::cout << it->first << " - " << it->second  << " / ";
	}
	std::cout << std::endl << std::endl;
	sortPairs(pairVector);
	std::cout << "Vector after " << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++) {
		std::cout << it->first << " - " << it->second  << " / ";
	}
}
