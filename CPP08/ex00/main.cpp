/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:34:53 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/17 17:26:17 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <list>
#include <deque>

int main() {
    try {
		std::cout << "+++++ TEST VECTOR +++++" << std::endl;
		std::vector<int> myVector(50, 1);
		easyfind(myVector, 1);
		myVector.erase(myVector.begin(), myVector.end());
    	easyfind(myVector, 1);
	}
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	try {
		std::cout << std::endl << "+++++ TEST LIST +++++" << std::endl;
		std::list<int> myList(50, 4);
		easyfind(myList, 4);
		myList.erase(myList.begin(), myList.end());
		easyfind(myList, 4);
	}
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	try {
		std::cout << std::endl << "+++++ TEST DEQUE +++++" << std::endl;
		std::deque<int> myDeck(50, 4);
		easyfind(myDeck, 4);
		myDeck.erase(myDeck.begin(), myDeck.end());
		easyfind(myDeck, 4);
	}
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}