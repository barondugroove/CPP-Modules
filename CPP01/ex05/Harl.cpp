/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:31:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 15:14:05 by bchabot          ###   ########.fr       */
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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "You may be talented but you're not Kanye West." << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Yo, Taylor, I'm really happy for you. Imma let you finish. But Beyoncé had one of the best videos of all time." << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I can analyze people's intentions. Immediately.That's just a warning. To everyone." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is the most offended I've ever been…this is the maddest I ever will be. I'm typing so fucking hard I might break my fucking Mac book Air!!!!!!!!" << std::endl;
}
