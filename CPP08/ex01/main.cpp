/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:50:31 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/11 14:59:37 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>
#include <climits>

std::list<int> createList(unsigned int size) {
	std::list<int> myNumberList;
	for (int i = 0; i < (int)size; i++)
		myNumberList.push_back(rand() % 10000 + 1);
	return myNumberList;
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "________ MY TESTS ________" << std::endl;
	Span sp2 = Span(10000);
	std::list<int> myList = createList(10000);
	std::list<int>::iterator ptr = myList.begin();
	for (; ptr != myList.end(); ptr++)
		std::cout << *ptr << std::endl;
	sp2.addMultipleNumbers(ptr, myList.end());
	return 0;
}