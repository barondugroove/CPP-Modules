/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/11 15:23:06 by bchabot          ###   ########.fr       */
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
		
		void	FordJohnsonSort();
		void	sortVec(std::vector<int> &_s);
		void	binarySearch(std::vector<int> &_s, int nbr);
		int		getJacobsthal(int n, int n1);

	private :
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		int					_size;
		int					_straggler;
		int					_n;
		int					_n1;
};

#endif
