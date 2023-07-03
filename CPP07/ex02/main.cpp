/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:33:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/03 18:09:54 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main(void) {
	int * a = new int();
	std::cout << a << std::endl;
	Array<int> b = Array<int>();
	std::cout << b.size() << std::endl;
	try {
		b.fillArray(51, 5);
	}
	catch (std::exception &e) {}
	return 0;
}