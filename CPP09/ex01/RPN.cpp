/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/08 19:45:19 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

void checkErrors(std::string &str) {
	if (str.empty() || str.find('(', 0) != std::string::npos || str.find(')', 0) != std::string::npos
	|| str.find('.', 0) != std::string::npos) {
		std::cerr << "Error." << std::endl;
		exit (1);
	}
}

int	isOperator(char &c) {
	char operators[4] = {'+', '-', '*', '/'};
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

void	calc(std::stack<int> &calculus, int i) {
	int (*operatorsFunc[4])(int &x, int &y) = {add, soustract, multiply, divide};
	
	if (calculus.size() < 2) {
		std::cout << "Error. Notation is erroneous." << std::endl;
		clearStack(calculus);
		exit (1);
	}
	int x = calculus.top();
	calculus.pop();
	int y = calculus.top();
	calculus.pop();
	if (i == 3 && x == 0) {
		std::cout << "Error. Division by 0 is impossible." << std::endl;
		clearStack(calculus);
		exit (1);
	}
	calculus.push(operatorsFunc[i](y, x));
}

void	rpn(std::string &str) {
	std::stack<int> calculus;
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (isdigit(*it))
			calculus.push(*it - '0');
		else if (isOperator(*it) != -1)
			calc(calculus, isOperator(*it));
	}
	std::cout << calculus.top() << std::endl;
}