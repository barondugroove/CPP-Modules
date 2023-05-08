/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:31:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/08 19:57:06 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

Harl::Harl(void) {
	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
	return ;
}

Harl::~Harl(void) {
	return ;
}

void Harl::complain(std::string level) {
	std::string comment[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (level == comment[i])
			(this->*func[i])();
}

void Harl::debug(void) {
	std::cout << ".\n";
}

void Harl::info(void) {
	std::cout << "Yo, Taylor, I'm really happy for you. Imma let you finish. But Beyoncé had one of the best videos of all time." << std::endl;
}

void Harl::warning(void) {
	std::cout << "it's a warning.\n";
}

void Harl::error(void) {
	std::cout << "it's an error.\n";
}
