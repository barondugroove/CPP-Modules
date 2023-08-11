/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/11 19:37:49 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe(char **av) {
	while (*av) {
		_vec.push_back(atoi(*av));
		av++;
	}
	_n = 0;
	_n1 = 2;
	_size = _vec.size();
	_straggler = -1;
	if (_size % 2 != 0)
		_straggler = _vec.back();
}

PmergeMe::~PmergeMe() {
}

void	PmergeMe::sortVec(std::vector<int> &_vec) {
	std::vector<int> vectorMax;
	std::vector<std::pair<int, int> > vectorPair;
	int	size;

	size = _vec.size();
	if (size < 2)
		return ;
	for (int i = 0; i < size - 1; i += 2) {
		if (_vec[i] > _vec[i + 1]) {
			vectorMax.push_back(_vec[i]);
			vectorPair.push_back(std::make_pair(_vec[i + 1], _vec[i]));
		}
		else {
			vectorMax.push_back(_vec[i + 1]);
			vectorPair.push_back(std::make_pair(_vec[i], _vec[i + 1]));
		}
	}
	if (size % 2 != 0) {
		vectorMax.push_back(_vec.back());
	}
	sortVec(vectorMax);

	_vec.clear();
    for (size_t i = 0; i < vectorMax.size(); i++) {
		_vec.push_back(vectorMax[i]);
	}
	
	for (size_t i = 0; i < vectorPair.size(); i++) {
		binarySearch(_vec, vectorPair[i].first);
    }

/*
	std::cout << "vec size is : " << _vec.size() << " _size : " << _size << std::endl;
	//if ((int)_vec.size() == _size) {
		std::cout << "n is : " << _n << " | n1 is : " << _n1 << std::endl;
		int	temp;
		temp = _n1; 
		_n1 = getJacobsthal(_n, _n1);
		if (_n1 > (int)_vec.size())
			_n1 = _vec.size();
		_n = temp;
		for (int i = _n1; i > _n; i--) {
			std::cout << "i is : " << i << std::endl;
			binarySearch(_vec, vectorPair[i].first);
		}
	}*/
}

void	PmergeMe::binarySearch(std::vector<int> &_vec, int nbr) {

	int	idxMin = 0;
	int idxMax = _vec.size();
	int middle = (idxMax - idxMin) / 2;;

	while ((idxMax - idxMin) > 1) {
		if (nbr > _vec[middle]) {
			idxMin = middle;
			middle += (idxMax - idxMin) / 2;
		}
		else {
			idxMax = middle;
			middle -= (idxMax - idxMin) / 2;
		}
	}
	std::vector<int>::iterator it;
	if (nbr > _vec[idxMin])
		it = _vec.begin() + idxMax;
	else
		it = _vec.begin() + idxMin;
	_vec.insert(it, nbr);
}

int	PmergeMe::getJacobsthal(int n, int n1) {
	return ((n * 2) + n1);
}

bool	is_sorted(std::vector<int> &_vec) {
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end() - 1; it++) {
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

void	PmergeMe::FordJohnsonSort() {
	std::cout << "Vector before " << std::endl;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	sortVec(_vec);
	if (_straggler != -1)
		binarySearch(_vec, _straggler);

	std::cout << std::endl << "Vector after " << std::endl;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << *it << " ";
	}

	if (is_sorted(_vec))
		std::cout << std::endl << std::endl << "CEST TRIE PUTAIN" << std::endl;
}
