/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:11:39 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/08 14:25:30 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 145, 137) {
    std::cout << "Presidential pardon form default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 145, 137), target(target) {
    std::cout << "Presidential pardon form target constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm(rhs) {
    std::cout << "Presidential pardon form copy constructor called." << std::endl;
    *this = rhs;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
    std::cout << "Presidential pardon form assignation operator called." << std::endl;
    if (this != &rhs)
		this->_signed = rhs.isSigned();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Presidential pardon form destructor called." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->checkSigning(executor.getGrade());
	if (!this->isSigned())
		throw AForm::FormNotSigned();
	std::cout << this->target << "has been forgiven by Zaphod Beeblerox." << std::endl;
}