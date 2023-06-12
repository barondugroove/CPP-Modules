/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:11:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 18:09:09 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void) 
{
	std::cout << std::endl;
    std::cout << "----------------CONSTRUCTOR MESSAGES----------------"<< std::endl;
	Bureaucrat first("Hermes Conrad", 1);
	Intern someRandomIntern;
	
    std::cout << std::endl << std::endl;
    std::cout << "----------------TEST OK ROBOTOMY----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
			AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            std::cout << *rrf << std::endl;
			first.signForm(*rrf);
			first.executeForm(*rrf);
			std::cout << std::endl;
			delete rrf;
        }
        catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
	std::cout << std::endl;
    std::cout << "----------------TEST NO CONTRACT----------------"<< std::endl;
    {
        try
        {
			AForm* rrf;
			rrf = someRandomIntern.makeForm("great reset", "Salomon Rothschild");
			delete rrf;
        }
        catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
}