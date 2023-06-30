/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:33:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/30 16:45:35 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"
#include <iostream>

int main(void) {
	int numbers[5] = {0,1,2,3,4};
	iter(numbers, 5, f);
	float floats[5] = {0.1f,1.1f,2.1f,3.1f,4.1f};
	iter(floats, 5, f);
	double doubles[5] = {0.01,1.01,2.01,3.01,4.01};
	iter(doubles, 5, f);
	char chars[5] = {'a','b','c','d','e'};
	iter(chars, 5, f);
	return 0;
}