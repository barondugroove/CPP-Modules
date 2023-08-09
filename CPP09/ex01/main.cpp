/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/09 14:38:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error." << std::endl;
		return 1;
	}
	std::string str = av[1];
	if (!checkErrors(str))
		return 1;
	rpn(str);
	return 0;
}