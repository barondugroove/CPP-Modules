/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:33:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/19 16:18:58 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Argument error." << std::endl << "Usage: ./convert [string]" << std::endl;
		return 0;
	}
	ScalarConverter sc = ScalarConverter();
	sc.convert(av[1]);
	return 0;
}