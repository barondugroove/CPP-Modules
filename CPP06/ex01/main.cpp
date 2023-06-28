/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:33:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/28 17:07:49 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

void printData(const Data &src) {
	std::cout << "double is : " << src.dbl << std::endl;
	std::cout << "float is : " << src.flt << std::endl;
	std::cout << "integer is : "  << src.integer << std::endl;
	std::cout << "string is : " << src.string << std::endl;
}

int main(void) {
	Data data;
	Data *data2;
	uintptr_t ptr;
	
	data.dbl = 42.0;
	data.flt = 25.8f;
	data.integer = 100;
	data.string = "Cereal Killer";

	std::cout << "------ Before serialization ------" << std::endl;
	printData(data);
	
	ptr = Serializer::serialize(&data);
	data2 = Serializer::deserialize(ptr);
	
	std::cout << std::endl << "------- After serialization ------" << std::endl;
	printData(*data2);
	return 0;
}