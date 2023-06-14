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

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5) {
    std::cout << "Presidential pardon form default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), target(target) {
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
	if (!this->isSigned())
		throw AForm::FormCantExec(executor.getName(), this->getName(), "form is not signed.");
	this->checkExec(executor);
	std::cout << this->target << "has been forgiven by Zaphod Beeblerox." << std::endl;
}