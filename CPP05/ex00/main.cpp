/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:11:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/06 18:10:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try {
        //Bureaucrat god("Anubis", 0);
        Bureaucrat secretary("Monica Lewinsky", 150);
        Bureaucrat president("Bill Clinton", 1);
        secretary.incrementGrade();
        std::cout << secretary.getName() << "'s grade is " << secretary.getGrade() << std::endl;
        secretary.decrementGrade();
        std::cout << secretary.getName() << "'s grade is " << secretary.getGrade() << std::endl;
        president.decrementGrade();
        std::cout << president.getName() << "'s grade is " << president.getGrade() << std::endl;
        president.incrementGrade();
        std::cout << president.getName() << "'s grade is " << president.getGrade() << std::endl;
        president.incrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
}