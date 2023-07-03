/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:30:29 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/03 14:05:59 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <iostream>
#include <climits>

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

bool isInf(const std::string to_convert) {
	if (to_convert == "inf" || to_convert == "+inf" || to_convert == "-inf" || to_convert == "inff" || to_convert == "+inff" || to_convert == "-inff")
		return (true);
	return (false);
}

void printNan(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void printChar(const char &c, const double &d) {
	if (d >= 32 && d <= 126)
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
}

void printInt(const int &nbr, const double &d) {
	if (d <= INT_MAX && d >= INT_MIN)
		std::cout << "int: " << nbr << std::endl;
	else
		std::cout << "int: overflow" << std::endl;
}

void printFloat(const float &nbr) {
	if (nbr >= 1000000 || (nbr - (int)nbr != 0))
		std::cout << "float: " << nbr << "f" << std::endl;
	else
		std::cout << "float: " << nbr << ".0f" << std::endl;
}

void printDouble(const double &nbr) {
	if (nbr >= 1000000 || (nbr - (int)nbr != 0))
		std::cout << "double: " << nbr << std::endl;
	else
		std::cout << "double: " << nbr << ".0" << std::endl;
}

void convertInt(std::string to_convert, const double &d) {
	int nbr = atoi(to_convert.c_str());
	
	printChar(static_cast<char>(nbr), d);
	printInt(nbr, d);
	printFloat(static_cast<float>(d));
	printDouble(static_cast<double>(d));
}

void convertFloat(std::string to_convert, const double &d) {
	float nbr = strtof(to_convert.c_str(), NULL);

	printChar(static_cast<char>(nbr), d);
	printInt(static_cast<int>(nbr), d);
	printFloat(d);
	printDouble(static_cast<double>(d));
}

void convertDouble(std::string to_convert) {
	double nbr = strtod(to_convert.c_str(), NULL);

	if (!isInf(to_convert))
		printChar(nbr, nbr);
	else
		std::cout << "char: impossible" << std::endl;
	if (!isInf(to_convert))
			printInt(static_cast<int>(nbr), nbr);
	else
		std::cout << "int: impossible" << std::endl;
	printFloat(static_cast<float>(nbr));
	printDouble(nbr);
}

void identify(const std::string &to_convert) {
	char *ptr;
	double d = strtod(to_convert.c_str(), &ptr);
	if (d != d) {
		printNan();
		return ;
	}
	if (to_convert.find(".") != std::string::npos && (*ptr == 'f' && *(ptr + 1) == '\0') && !isInf(to_convert))
		convertFloat(to_convert, d);
	else if (to_convert.find(".") == std::string::npos && *ptr == '\0' && !isInf(to_convert))
		convertInt(to_convert, d);
	else if ((to_convert.find(".") != std::string::npos && *ptr == '\0') || isInf(to_convert))
		convertDouble(to_convert);
	else
		std::cout << "Impossible conversion, check your argument." << std::endl;
}

void ScalarConverter::convert(const std::string &to_convert) {
	if (to_convert.empty()) {
		std::cout << "Impossible conversion, check your argument." << std::endl;
		return ;
	}
	if (to_convert.length() == 1 && !isdigit(to_convert[0])) {
		std::cout << "char: " << to_convert[0] << std::endl;
		std::cout << "int: " << static_cast<int>(to_convert[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(to_convert[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(to_convert[0]) << ".0" << std::endl;
		return ;
	}
	identify(to_convert);
	return ;
}