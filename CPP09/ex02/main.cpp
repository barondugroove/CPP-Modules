/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/10 14:06:03 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>
#include <cerrno>

static bool	isValid(const std::string &nbr) {
	long	test;
	char	*ptr;

	test = strtol(nbr.c_str(), &ptr, 10);
	if (errno != ERANGE && *ptr == '\0' && test >= 0 && test < INT_MAX)
		return true;
	return false;
}

static bool	checkErrors(char **av) {
	if (*av[0] == '\0')
		return false;
	while (*av) {
		if (!isValid(*av))
			return false;
		av++;
	}
	return true;
}

int main(int ac, char **av)
{
	if (ac < 2 || !checkErrors(++av)) {
		std::cout << "Error. Check arguments." << std::endl;
		return 1;
	}
	PmergeMe s = PmergeMe(av);
	s.FordJohnsonSort();
	return 0;
}