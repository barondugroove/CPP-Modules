/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:16:52 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/09 16:48:47 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern& Intern::operator=(Intern const &rhs) {
	(void)rhs;
	std::cout << "Intern assignation operator called." << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

const char* Intern::NoContract::watch() const throw() {
	return ("Name provided does not match any contract template.");
}

AForm* formFactory(int idx, std::string const & target) {
	switch (idx)
		{
			case 0:
				return (new PresidentialPardonForm(target));
				break;
			case 1:
				return (new RobotomyRequestForm(target));
				break;
			case 2:
				return (new ShrubberyCreationForm(target));
				break;
			default:
				throw Intern::NoContract();
				break;
		}
}

AForm* Intern::makeForm(std::string const & name, std::string const & target) {
	AForm *newForm = NULL;
	std::string const formName[3] = {"presidential pardon", "robotomy request", "shrubbery form"};
	
	for (int i = 0; i < 3; i++)
		if (!name.compare(formName[i]))
			newForm = formFactory(i, target);
	std::cout << "Interm creates " << name << " form." << std::endl;
	return newForm;
}