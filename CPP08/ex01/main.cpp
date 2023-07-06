/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:50:31 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/06 13:11:49 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>

std::list<int> createList(unsigned int size) {
	std::list<int> myNumberList;
	for (int i = 0; i < (int)size; i++)
		myNumberList.push_back(rand() % INT_MAX + 1);
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
	std::list<int> myList = createList(5);
	std::list<int>::iterator ptr = myList.begin();
	for (; ptr != myList.end(); ptr++)
		std::cout << *ptr << std::endl;
	return 0;
}