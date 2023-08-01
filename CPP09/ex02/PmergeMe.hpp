/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/01 16:14:39 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <list>
#include <vector>
#include <string>
#include <iostream>

class PmergeMe {
	public :
		PmergeMe(char **av);
		~PmergeMe();

		void	FordJohnsonSort();
		void	createPairs(std::vector<std::pair<int, int> > &pairVector, std::vector<int> &s);
		void	sortPairs(std::vector<std::pair<int, int> > &pairVector);
		void	mergePairs(std::vector<std::pair<int, int> > &resultVector, std::vector<std::pair<int, int> > &vector1, std::vector<std::pair<int, int> > &vector2);

	private :
		std::vector<int>	_s;
		int					_size;
		int					_straggler;
};

#endif
