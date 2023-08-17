/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/17 17:29:29 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool checkErrors(std::string &str) {
	if (str.empty() || str.find('(', 0) != std::string::npos || str.find(')', 0) != std::string::npos
	|| str.find('.', 0) != std::string::npos) {
		return false;
	}

	for (int i = 0; i < (int)str.size() - 1; i++) {
		if (isdigit(str[i]) && isdigit(str[i + 1]))
			return false;
	}
	return true;
}

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error." << std::endl;
		return 1;
	}
	std::string str = av[1];
	if (!checkErrors(str)) {
		std::cerr << "Error." << std::endl;
		return 1;
	}
	RPN::rpn(str);
	return 0;
}
