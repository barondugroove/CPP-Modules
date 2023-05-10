/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:31:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 15:17:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

Harl::Harl(void) {
	return ;
}

Harl::~Harl(void) {
	return ;
}

void Harl::complain(int level) {
	std::string comment[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (level && level <= 4)
	{
		switch (level - 1)
		{
			case 0:
				debug();
				break;
			case 1:
				info();
				break;
			case 2:
				warning();
				break;
			case 3:
				error();
				break;
			default:
				break;
		}
		level++;
	}
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
	std::cout << "This is the most offended I’ve ever been…this is the maddest I ever will be. I’m typing so fucking hard I might break my fucking Mac book Air!!!!!!!!" << std::endl;
}
