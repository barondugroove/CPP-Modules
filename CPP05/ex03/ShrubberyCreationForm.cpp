/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:11:39 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/13 15:39:57 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137) {
    std::cout << "Shrubbery creation form default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), target(target) {
    std::cout << "Shrubbery creation form target constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm(rhs) {
    std::cout << "Shrubbery creation form copy constructor called." << std::endl;
    *this = rhs;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
    std::cout << "Shrubbery creation form assignation operator called." << std::endl;
    if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubbery creation form destructor called." << std::endl;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw AForm::FormCantExec(executor.getName(), this->getName(), "form is not signed.");
	this->checkExec(executor);
	
	std::ofstream	outfile;
	std::string		filename = target + "_shrubbery";
	outfile.open(filename.c_str());
	outfile << "tree tree tree \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	outfile << "    *	    	*		\n";
	outfile << "   /.\\        /.\\	 	\n";
	outfile << "  /o..\\      /o.\\		\n";
	outfile << "  /..o\\     /.o.\\		\n";
	outfile << " /.o..o\\   /.o..o\\	\n";
	outfile << "/...o...\\ /...o...\\	\n";
	outfile << "/..o....\\ /..o.....\\	\n";
	outfile << "^^^[_]^^^  ^^^[_]^^^	\n";
}