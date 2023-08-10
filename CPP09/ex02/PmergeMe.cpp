/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/10 16:01:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe(char **av) {
	while (*av) {
		_s.push_back(atoi(*av));
		av++;
	}
	_n = 0;
	_n1 = 2;
	_size = _s.size();
	_straggler = -1;
	if (_size % 2 != 0)
		_straggler = _s.back();
}

PmergeMe::~PmergeMe() {
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
	if (size % 2 != 0) {
		vectorMax.push_back(_s.back());
	}

	sortPairs(vectorMax);

	_s.clear();
    for (size_t i = 0; i < vectorMax.size(); i++) {
		_s.push_back(vectorMax[i]);
	}
	
	for (size_t i = 0; i < vectorPair.size(); i++) {
		binarySearch(_s, vectorPair[i].first);
    }
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

bool	is_sorted(std::vector<int> &_s) {
	for (std::vector<int>::iterator it = _s.begin(); it != _s.end() - 1; it++) {
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

void	PmergeMe::FordJohnsonSort() {
	std::cout << "Vector before " << std::endl;
	for (std::vector<int>::iterator it = _s.begin(); it != _s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	sortPairs(_s);
	if (_straggler != -1)
		binarySearch(_s, _straggler);

	std::cout << std::endl << "Vector after " << std::endl;
	for (std::vector<int>::iterator it = _s.begin(); it != _s.end(); it++) {
		std::cout << *it << " ";
	}

	if (is_sorted(_s))
		std::cout << std::endl << std::endl << "CEST TRIE PUTAIN" << std::endl;
}
