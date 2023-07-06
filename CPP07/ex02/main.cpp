/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:33:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/06 11:21:42 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main(void) {
	Array<int> b(5);
	Array<int> a;
	Array<float> c(15);
	try {
		std::cout << "________TEST ALL GOOD________" << std::endl;
		std::cout << "size of b is " << b.size() << std::endl;
		b.fillArray(10, 0);
		std::cout << "b[0] is " << b[0] << std::endl;
		b.fillArray(1, 1);
		std::cout << "b[1] is " << b[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "________TEST COPY________" << std::endl;
		a = b;
		std::cout << "size of a is " << a.size() << std::endl;
		std::cout << "a[0] before fill is " << a[0] << std::endl;
		a.fillArray(55, 0);
		std::cout << "a[0] after fill is " << a[0] << std::endl;
		std::cout << "b[0] is still " << b[0] << std::endl;
		std::cout << "a[1] is " << a[1] << std::endl;
		std::cout << "b[1] is " << b[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "________BAD INDEX CREATE ARRAY<T>________" << std::endl;
		Array<int> d(-1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "________BAD INDEX FILL ARRAY________" << std::endl;
		c.fillArray(0.1, -1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "________BAD INDEX OPERATOR []________" << std::endl;
		std::cout << c[15] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}