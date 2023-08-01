/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/25 17:27:30 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <string>
#include <iostream>

void checkErrors(std::string str) {
	if (str.empty() || str.find('(', 0) != std::string::npos || str.find(')', 0) != std::string::npos
	|| str.find('.', 0) != std::string::npos) {
		std::cerr << "Error." << std::endl;
		exit (1);
	}
}

int	isOperator(char c) {
	char operators[4] = {'+', '-', '*', '/'};
	for (int i = 0; i < 4; i++)
		if (c == operators[i])
			return i;
	return -1;
}

int add(int x, int y) {
	return (x + y);
}

int soustract(int x, int y) {
	return (x - y);
}

int multiply(int x, int y) {
	return (x * y);
}

int divide(int x, int y) {
	return (x / y);
}

void	calc(std::stack<int> &calculus, int i) {
	int (*operatorsFunc[4])(int x, int y) = {add, soustract, multiply, divide};
	int x = calculus.top();
	calculus.pop();
	int y = calculus.top();
	calculus.pop();
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