/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:11:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 11:17:25 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try {
		std::cout << "----------------TEST GRADE TOO HIGH----------------"<< std::endl;
        Bureaucrat god("Anubis", 0);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	try {
		std::cout << std::endl << std::endl;
		std::cout << "----------------TEST GRADE TOO LOW----------------"<< std::endl;
		
        Bureaucrat god("Anubis", 200);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	
    try {
		std::cout << std::endl;
		std::cout << "----------------TEST INCREMENT/DECREMENT----------------"<< std::endl;
		Bureaucrat secretary("Monica Lewinsky", 150);
        Bureaucrat president("Bill Clinton", 1);

		std::cout << std::endl;
        secretary.incrementGrade();
        std::cout << secretary;
        secretary.decrementGrade();
        std::cout << secretary;
        president.decrementGrade();
        std::cout << president;
        president.incrementGrade();
        std::cout << president;
        president.incrementGrade();
        std::cout << president;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}