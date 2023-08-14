/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/14 17:35:13 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <iostream>

class PmergeMe {
	public :
		PmergeMe(char **av);
		~PmergeMe();

		void	FordJohnsonSortVec(char **av);
		void	sortVec(std::vector<int> &_s);
		void	binarySearchVec(std::vector<int> &_s, int nbr);

		void	FordJohnsonSortDeq(char **av);
		void	sortDeq(std::deque<int> &_s);
		void	binarySearchDeq(std::deque<int> &_s, int nbr);

		int		getJacobsthal(int n, int n1);
		void	displayTimer(char **av);

		bool	is_sorted(std::vector<int> &_vec);
		bool	is_sortedDeq(std::deque<int> &_deq);

	private :
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		int					_size;
		int					_straggler;
		int					_n;
		int					_n1;
		double				_vecTimer;
		double				_deqTimer;
};

#endif
