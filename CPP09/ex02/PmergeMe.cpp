/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/16 17:54:02 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

double	getTime(double timer) {
	std::clock_t c_start = std::clock();
	return (c_start - timer);
}

void	PmergeMe::displayTimer(char **av) {
	std::cout << "Before:	";
	for (int i = 0; av[i] ; i++) {
		std::cout << av[i];
		if (av[i + 1])
			std::cout << " ";
	}
	std::cout << std::endl << "After:	";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << *it;
		if ((it + 1) != _vec.end())
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
}

PmergeMe::~PmergeMe() {
}

void	PmergeMe::FordJohnsonSortVec(char **av) {
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

void	reorderVecPairs(std::vector<int> &vectorMax, std::vector<std::pair<int, int> > &vectorPair) {
	std::vector<std::pair<int, int> > vectorCopy = vectorPair;

	for (size_t i = 0; i < vectorMax.size(); i++) {
		int j = 0;
		if (vectorMax[i] != vectorPair[i].second) {
			while (vectorMax[i] != vectorPair[j].second)
				j++;
			vectorCopy[i].first = vectorPair[j].first;
			vectorCopy[i].second = vectorPair[j].second;

		}
	}
	vectorPair = vectorCopy;
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

	if ((int)vectorPair.size() == _size / 2) {
		reorderVecPairs(vectorMax, vectorPair);
		_vec.insert(_vec.begin(), vectorPair[0].first);
		vectorPair.erase(vectorPair.begin());
	}

	for (size_t i = 0; i < vectorPair.size(); i++) {
		binarySearchVec(_vec, vectorPair[i].first);
	}

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
	while (*av) {
		_deq.push_back(atoi(*av));
		av++;
	}

	sortDeq(_deq);
	if (_straggler != -1)
		binarySearchDeq(_deq, _straggler);
}

void	reorderDeqPairs(std::deque<int> &deqMax, std::deque<std::pair<int, int> > &deqPair) {
	std::deque<std::pair<int, int> > deqCopy = deqPair;

	for (size_t i = 0; i < deqMax.size(); i++) {
		int j = 0;
		if (deqMax[i] != deqPair[i].second) {
			while (deqMax[i] != deqPair[j].second)
				j++;
			deqCopy[i].first = deqPair[j].first;
			deqCopy[i].second = deqPair[j].second;

		}
	}
	deqPair = deqCopy;
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
	if ((int)dequePair.size() == _size / 2) {
		reorderDeqPairs(dequeMax, dequePair);
		_deq.insert(_deq.begin(), dequePair[0].first);
		dequePair.erase(dequePair.begin());
	}

	for (size_t i = 0; i < dequePair.size(); i++) {
		binarySearchDeq(_deq, dequePair[i].first);
	}
}

void	PmergeMe::binarySearchDeq(std::deque<int> &_deq, int nbr) {

	int	idxMin = 0;
	int idxMax = _deq.size();
	int middle = (idxMax - idxMin) / 2;

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

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	(void)rhs;
	return *this;
}
