/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:11:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 15:56:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void) 
{
	std::cout << std::endl;
    std::cout << "----------------CONSTRUCTOR MESSAGES----------------"<< std::endl;
	AForm* pres = new PresidentialPardonForm("Alexandre Benalla");
	AForm* shrub = new ShrubberyCreationForm("Amazonia");
	AForm* robot = new RobotomyRequestForm("Zied Harzi");
	Bureaucrat first("Satan", 1);
	Bureaucrat second("God", 150);
	
    std::cout << std::endl << std::endl;
    std::cout << "----------------TEST FORM NOT SIGNED----------------"<< std::endl;
    std::cout << std::endl;
    {
        try {
			std::cout << *pres << std::endl;
			first.executeForm(*pres);
        }
        catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "----------------TEST FORM SIGNED----------------"<< std::endl;
    std::cout << std::endl;
    {
        try {
			std::cout << *shrub << std::endl;
            first.signForm(*shrub);
			first.executeForm(*shrub);
        }
        catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "----------------TEST GRADE TOO LOW----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
			std::cout << *robot << std::endl;
            first.signForm(*robot);
			second.executeForm(*robot);
        }
        catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
	std::cout << std::endl;
    std::cout << "----------------TEST OK ROBOTOMY----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
			std::cout << *robot << std::endl;
            first.executeForm(*robot);
        }
        catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
	
	std::cout << std::endl;
    std::cout << "----------------DESTRUCTOR MESSAGES----------------"<< std::endl;
	delete pres;
	delete shrub;
	delete robot;
}