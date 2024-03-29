/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:50:31 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/26 15:18:37 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>
#include <climits>

std::list<int> createList(unsigned int size) {
	srand(clock());
	std::list<int> myNumberList;
	for (int i = 0; i < (int)size; i++)
		myNumberList.push_back(rand() % INT_MAX);
	return myNumberList;
}

int main()
{
	try {
		std::cout << "________ SUBJECT TESTS ________" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "________ MY TESTS ________" << std::endl;
		Span sp2 = Span(10000);
		std::list<int> myList = createList(10000);
		std::list<int>::iterator ptr = myList.begin();

		sp2.addMultipleNumbers(ptr, myList.end());
		std::cout << "Shortest span is : " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span is : " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "________ TEST EMPTY ARRAY ________" << std::endl;
		Span sp3;
		sp3.shortestSpan();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "________ TEST FULL ARRAY ________" << std::endl;
		Span sp2 = Span(10000);
		std::list<int> myList = createList(10000);
		sp2.addMultipleNumbers(myList.begin(), myList.end());
		sp2.addNumber(25);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
