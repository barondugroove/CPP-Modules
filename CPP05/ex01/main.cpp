/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:11:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/08 16:27:39 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) 
{
    std::cout << std::endl;
    std::cout << "----------------TEST----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form1("CACA", 150, 0);
        }
        catch(Form::GradeTooHighException & e)
        {
            std::cout << e.what() << std::endl;
        }
	    catch(Form::GradeTooLowException & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "----------------TEST----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form1("CACA", 150, 151);
        }
        catch(Form::GradeTooHighException & e)
        {
            std::cout << e.what() << std::endl;
        }
	    catch(Form::GradeTooLowException & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "----------------TEST----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form1("CACA", 150, 150);
        }
        catch(Form::GradeTooHighException & e)
        {
            std::cout << e.what() << std::endl;
        }
	    catch(Form::GradeTooLowException & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "----------------TEST----------------"<< std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form form("Contract");
			Form form1("Devil's Contract", 150, 150);
            Bureaucrat first("Satan", 5);
            Bureaucrat second("God", 150);

            std::cout << first << std::endl;
			std::cout << form1 << std::endl;
            std::cout << second << std::endl;

            first.signForm(form1);
			std::cout << form1 << std::endl;
            //first.signForm(form1);
            second.signForm(form);
            
        }
        catch(Form::GradeTooLowException & e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(Form::FormAlreadySigned & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}