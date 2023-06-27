/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:30:29 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/27 18:25:22 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <cmath>

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

void printNan(const std::string &to_convert) {
	std::string buf = "nan";
	if (to_convert == "nanf")
		buf = "nanf";
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << buf << std::endl;
	std::cout << "double: " << buf << std::endl;
}

void convertInt(const int &nbr, const double &d) {
	if (nbr >= 32 && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	
	if (d <= INT_MAX)
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	else
		std::cout << "int: overflow" << std::endl;
	
	if (nbr >= 100000) {
		std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
	}
}

void convertDouble(double nbr) {
	if (nbr >= 32 && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	
	if (nbr <= INT_MAX)
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	else
		std::cout << "int: overflow" << std::endl;
	
	if (nbr >= 100000) {
		std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << nbr << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << nbr << std::endl;
	}
}

void convertFloat(const float &nbr, const double &d) {
	if (nbr >= 32 && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	
	if (d <= INT_MAX)
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	else
		std::cout << "int: overflow" << std::endl;
	
	if (d >= 100000) {
		std::cout << "float: " << nbr << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	}
	else {
		std::cout << "float: " << nbr << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;	
	}
}

void identify(const std::string &to_convert) {
	char *ptr;
	double d = strtod(to_convert.c_str(), &ptr);
	if (*ptr != '\0' && *ptr != 'f') {
		std::cout << "Impossible conversion, check your argument." << std::endl;
		return ;
	}
	if (d != d) {
		printNan(to_convert);
		return ;
	}
	if (*ptr == 'f')
		convertFloat(strtof(to_convert.c_str(), NULL), d);
	else if (to_convert.find(".") == std::string::npos && *ptr == '\0' && (d >= INT_MIN && d <= INT_MAX))
		convertInt(atoi(to_convert.c_str()), d);
	else
		convertDouble(d);
}

void ScalarConverter::convert(const std::string &to_convert) {
	if (to_convert.length() == 1 && (!isdigit(to_convert[0]) || (to_convert[0] >= '0' && to_convert[0] <= '9'))) {
		std::cout << "char: " << to_convert[0] << std::endl;
		std::cout << "int: " << static_cast<int>(to_convert[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(to_convert[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(to_convert[0]) << ".0" << std::endl;
		return ;
	}
	identify(to_convert);
	return ;
}