/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:11:39 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/09 16:27:38 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib> 
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
    std::cout << "Robotomy request form default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << "Robotomy request form target constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm(rhs) {
    std::cout << "Robotomy request form copy constructor called." << std::endl;
    *this = rhs;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
    std::cout << "Robotomy request form assignation operator called." << std::endl;
    if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy request form destructor called." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->checkSigning(executor.getGrade());
	if (!this->isSigned())
		throw AForm::FormNotSigned();
	std::cout << "rizzz rizzz rizzz rizzz rrrrrrrrrrrrr" << std::endl;
	if (rand() % 2 == 0)
		std::cout << "Lobotomization successful." << std::endl;
	else
		std::cout << "Lobotomization failed." << std::endl;
}