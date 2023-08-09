/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/09 17:55:24 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

class PmergeMe {
	public :
		PmergeMe(char **av);
		~PmergeMe();
		
		void	FordJohnsonSort();
		void	createPairs(std::vector<std::pair<int, int> > &pairVector, std::vector<int> &s);
		void	sortPairs(std::vector<int> &_s);
		void	binarySearch(std::vector<int> &_s, int nbr);
		int		getJacobsthal(int n, int n1);

	private :
		std::vector<int>	_s;
		int					_size;
		int					_straggler;
};

#endif
