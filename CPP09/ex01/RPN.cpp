/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/17 18:23:43 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

static int	isOperator(char &c) {
	static const char operators[4] = {'+', '-', '*', '/'};
	for (int i = 0; i < 4; i++)
		if (c == operators[i])
			return i;
	return -1;
}

static double add(double &first, double &second) {
	double test = first + second;
	if (test > INT_MAX)
		return (INT_OVERFLOW);
	return (second + first);
}

static double soustract(double &first, double &second) {
	double test = first - second;
	if (test < INT_MIN)
		return (INT_OVERFLOW);
	return (first - second);
}

static double multiply(double &first, double &second) {
	double test = first * second;
	if (test > INT_MAX || test < INT_MIN)
		return (INT_OVERFLOW);
	return (second * first);
}

static double divide(double &first, double &second) {
	return (first / second);
}

static bool	calc(std::stack<int> &calculus, int i) {
	static double (*operatorsFunc[4])(double &x, double &y) = {add, soustract, multiply, divide};

	if (calculus.size() < 2 || i == -1) {
		std::cerr << "Error. Notation is erroneous." << std::endl;
		return false;
	}
	double second = calculus.top();
	calculus.pop();
	double first = calculus.top();
	calculus.pop();
	if (i == 3 && second == 0) {
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

void	RPN::rpn(std::string &str) {
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

RPN::RPN() {
}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {
}

RPN &RPN::operator=(RPN const &rhs) {
	(void)rhs;
	return *this;
}
