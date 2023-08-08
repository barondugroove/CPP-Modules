/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/08 17:37:03 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Error." << std::endl;
		return 1;
	}
	PmergeMe s = PmergeMe(av);
	s.FordJohnsonSort();
	return 0;
}