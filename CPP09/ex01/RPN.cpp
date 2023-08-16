/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/16 12:15:30 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

bool checkErrors(std::string &str) {
	if (str.empty() || str.find('(', 0) != std::string::npos || str.find(')', 0) != std::string::npos
	|| str.find('.', 0) != std::string::npos) {
		std::cerr << "Error." << std::endl;
		return false;
	}

	for (int i = 0; i < (int)str.size() - 1; i++) {
		if (isdigit(str[i]) && isdigit(str[i + 1]))
			return false;
	}
	return true;
}

int	isOperator(char &c) {
	static const char operators[4] = {'+', '-', '*', '/'};
	for (int i = 0; i < 4; i++)
		if (c == operators[i])
			return i;
	return -1;
}

double add(double &first, double &second) {
	double test = first + second;
	if (test > INT_MAX)
		return (INT_OVERFLOW);
	return (second + first);
}

double soustract(double &first, double &second) {
	double test = first - second;
	if (test < INT_MIN)
		return (INT_OVERFLOW);
	return (first - second);
}

double multiply(double &first, double &second) {
	double test = first * second;
	if (test > INT_MAX || test < INT_MIN)
		return (INT_OVERFLOW);
	return (second * first);
}

double divide(double &first, double &second) {
	return (first / second);
}

bool	calc(std::stack<int> &calculus, int i) {
	static double (*operatorsFunc[4])(double &x, double &y) = {add, soustract, multiply, divide};

	if (calculus.size() < 2 || i == -1) {
		std::cerr << "Error. Notation is erroneous." << std::endl;
		return false;
	}
	double second = calculus.top();
	calculus.pop();
	double first = calculus.top();
	calculus.pop();
	if (i == 3 && first == 0) {
		std::cerr << "Error. Division by 0 is impossible." << std::endl;
		return false;
	}
	if (operatorsFunc[i](first, second) != INT_OVERFLOW)
		calculus.push(static_cast<int>(operatorsFunc[i](first, second)));
	else {
		std::cout << "Error. Result overflow" << std::endl;
		return false;
	}
	return true;
}

void	rpn(std::string &str) {
	std::stack<int> calculus;

	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (isdigit(*it))
			calculus.push(*it - '0');
		else if (*it != ' ' && !calc(calculus, isOperator(*it))) {
				return;
		}
	}
	if (calculus.size() == 1)
		std::cout << calculus.top() << std::endl;
	else
		std::cout << "Error. Notation is erroneous." << std::endl;
}
