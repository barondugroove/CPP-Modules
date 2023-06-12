/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:11:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 12:01:43 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) 
{
    std::cout << std::endl;
    std::cout << "----------------TEST FORM GRADE TOO HIGH----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form1("Devil's Deal", 150, 0);
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "----------------TEST FORM GRADE TOO LOW----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form1("Devil's Deal", 150, 151);
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "----------------TEST SIGN----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form("Contract");
			Form form1("Devil's Deal", 150, 150);
            Bureaucrat first("Satan", 1);
            Bureaucrat second("God", 150);
			std::cout << std::endl;

			std::cout << form1 << std::endl;
			std::cout << form << std::endl;
			
            first.signForm(form1);
			std::cout << form1 << std::endl;
            second.signForm(form);
            
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
	std::cout << std::endl;
    std::cout << "----------------TEST ALREADY SIGNED----------------"<< std::endl;
    std::cout << std::endl;
    {
		   try
        {
			Form form1("Devil's Deal", 1, 1);
            Bureaucrat first("Satan", 1);

			std::cout << form1 << std::endl;
			
            first.signForm(form1);
			std::cout << form1 << std::endl;
            first.signForm(form1);
            
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}