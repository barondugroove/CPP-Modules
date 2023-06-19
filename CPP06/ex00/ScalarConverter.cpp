/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:30:29 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/19 16:27:19 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <iostream>

ScalarConverter::ScalarConverter(void) {
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	*this = src;
	return ;
}

ScalarConverter::~ScalarConverter(void) {
	return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

void ScalarConverter::convert(const std::string &to_convert) {
	if (to_convert.length() == 1 && !isdigit(to_convert[0])) {
		std::cout << "char: " << static_cast<char>(to_convert[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(to_convert[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(to_convert[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(to_convert[0]) << ".0" << std::endl;
		return ;
	}
	long double d = strtold(to_convert.c_str(), NULL);
	std::cout << static_cast<char>(d) << std::endl;
	std::cout << static_cast<int>(d) << std::endl;
	std::cout << static_cast<double>(d) << ".0" << std::endl;
	std::cout << static_cast<float>(d) << ".0f" << std::endl;
	return ;
}