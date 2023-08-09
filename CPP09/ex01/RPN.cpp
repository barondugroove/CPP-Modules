/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/09 14:36:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

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

int add(int &x, int &y) {
	return (x + y);
}

int soustract(int &x, int &y) {
	return (x - y);
}

int multiply(int &x, int &y) {
	return (x * y);
}

int divide(int &x, int &y) {
	return (x / y);
}

void	clearStack(std::stack<int> &calculus) {
	for (int i = 0; i < (int)calculus.size(); i++) {
		calculus.pop();
	}
}

bool	calc(std::stack<int> &calculus, int i) {
	static int (*operatorsFunc[4])(int &x, int &y) = {add, soustract, multiply, divide};
	
	if (calculus.size() < 2 || i == -1) {
		std::cout << "Error. Notation is erroneous." << std::endl;
		//clearStack(calculus);
		return false;
	}
	int x = calculus.top();
	calculus.pop();
	int y = calculus.top();
	calculus.pop();
	if (i == 3 && x == 0) {
		std::cout << "Error. Division by 0 is impossible." << std::endl;
		clearStack(calculus);
		return false;
	}
	calculus.push(operatorsFunc[i](y, x));
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
	std::cout << calculus.top() << std::endl;
}