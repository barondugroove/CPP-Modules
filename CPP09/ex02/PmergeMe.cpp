/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/16 12:50:29 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

double	getTime(double timer) {
	std::clock_t c_start = std::clock();
	return c_start - timer;
}

void	PmergeMe::displayTimer(char **av) {
	std::cout << "Before: ";
	for (int i = 0; av[i] ; i++) {
		std::cout << av[i];
		if (av[i + 1])
			std::cout << " ";
	}
	std::cout << std::endl << "After: ";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << *it;
		if (*(it + 1))
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _size << " elements whith std::vector : " << _vecTimer << "us" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements whith std::deque : " << _deqTimer << "us" << std::endl;
}

PmergeMe::PmergeMe(char **av) {
	_n = 0;
	_n1 = 2;
	_straggler = -1;

	_vecTimer = getTime(0);
	this->FordJohnsonSortVec(av);
	_vecTimer = getTime(_vecTimer);

	_deqTimer = getTime(0);
	this->FordJohnsonSortDeq(av);
	_deqTimer = getTime(_deqTimer);

	displayTimer(av);
	if (is_sorted(_vec))
		std::cout << std::endl << std::endl << "CEST TRIE PUTAIN" << std::endl;
	if (is_sortedDeq(_deq))
		std::cout << "CEST TRIE LE DEQ" << std::endl;
}

PmergeMe::~PmergeMe() {
}

int	PmergeMe::getJacobsthal(int n, int n1) {
	return ((n * 2) + n1);
}

bool	PmergeMe::is_sorted(std::vector<int> &_vec) {
	if ((int)_vec.size() != _size)
		return false;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end() - 1; it++) {
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

bool	PmergeMe::is_sortedDeq(std::deque<int> &_deq) {
	if ((int)_deq.size() != _size)
		return false;
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end() - 1; it++) {
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

void	PmergeMe::FordJohnsonSortVec(char **av) {
	_vecTimer = getTime(0);
	while (*av) {
		_vec.push_back(atoi(*av));
		av++;
	}
	_size = _vec.size();
	if (_size % 2 != 0)
		_straggler = _vec.back();

	sortVec(_vec);
	if (_straggler != -1)
		binarySearchVec(_vec, _straggler);
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
	if (size % 2 != 0 && (int)vectorMax.size() != _size / 2) {
		vectorMax.push_back(_vec.back());
	}
	sortVec(vectorMax);
	_vec.clear();

	for (size_t i = 0; i < vectorMax.size(); i++) {
		_vec.push_back(vectorMax[i]);
	}

	for (size_t i = 0; i < vectorPair.size(); i++) {
		binarySearchVec(_vec, vectorPair[i].first);
	}


/*	std::cout << size << " | " << _size << std::endl;
	std::cout << "n is : " << _n << " | n1 is : " << _n1 << std::endl;
	for (int i = _n1 - 1; i >= _n; i--) {
			std::cout << "i is : " << i << std::endl;
			std::cout << "vectorPair[i] is " << vectorPair[i].first << "-" << vectorPair[i].second << std::endl;
			if (vectorPair[i].first) {
				binarySearchVec(_vec, vectorPair[i].first);
				vectorPair.erase(vectorPair.begin() + i);
			}
	}
	int	temp;
	temp = _n1;
	_n1 = getJacobsthal(_n, _n1);
	if (_n1 > size)
		_n1 = size;
	_n = temp;
*/
}

void	PmergeMe::binarySearchVec(std::vector<int> &_vec, int nbr) {

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

void	PmergeMe::FordJohnsonSortDeq(char **av) {
	_deqTimer = getTime(0);
	while (*av) {
		_deq.push_back(atoi(*av));
		av++;
	}
	_size = _deq.size();

	sortDeq(_deq);
	if (_straggler != -1)
		binarySearchDeq(_deq, _straggler);
}

void	PmergeMe::sortDeq(std::deque<int> &_deq) {
	std::deque<int> dequeMax;
	std::deque<std::pair<int, int> > dequePair;
	int	size;

	size = _deq.size();
	if (size < 2)
		return ;
	for (int i = 0; i < size - 1; i += 2) {
		if (_deq[i] > _deq[i + 1]) {
			dequeMax.push_back(_deq[i]);
			dequePair.push_back(std::make_pair(_deq[i + 1], _deq[i]));
		}
		else {
			dequeMax.push_back(_deq[i + 1]);
			dequePair.push_back(std::make_pair(_deq[i], _deq[i + 1]));
		}
	}
	if (size % 2 != 0 && (int)dequeMax.size() != _size / 2) {
		dequeMax.push_back(_vec.back());
	}
	sortDeq(dequeMax);
	_deq.clear();

	for (size_t i = 0; i < dequeMax.size(); i++) {
		_deq.push_back(dequeMax[i]);
	}

	for (size_t i = 0; i < dequePair.size(); i++) {
		binarySearchDeq(_deq, dequePair[i].first);
	}
}

void	PmergeMe::binarySearchDeq(std::deque<int> &_deq, int nbr) {

	int	idxMin = 0;
	int idxMax = _deq.size();
	int middle = (idxMax - idxMin) / 2;;

	while ((idxMax - idxMin) > 1) {
		if (nbr > _deq[middle]) {
			idxMin = middle;
			middle += (idxMax - idxMin) / 2;
		}
		else {
			idxMax = middle;
			middle -= (idxMax - idxMin) / 2;
		}
	}
	std::deque<int>::iterator it;
	if (nbr > _deq[idxMin])
		it = _deq.begin() + idxMax;
	else
		it = _deq.begin() + idxMin;
	_deq.insert(it, nbr);
}
