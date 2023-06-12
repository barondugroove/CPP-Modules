/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:07:40 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 16:10:55 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>
#include <iostream>

AForm::AForm() : _signGrade(1), _execGrade(1) {
    std::cout << "AForm default constructor called." << std::endl;
    this->_signed = 0;
}

AForm::AForm(std::string name, unsigned int sign, unsigned int exec) : _name(name), _signGrade(sign), _execGrade(exec) {
	checkGrade(sign);
	checkGrade(exec);
	std::cout << "AForm name constructor called." << std::endl;
    this->_signed = 0;
}

AForm::AForm(unsigned int sign, unsigned int exec) : _signGrade(sign), _execGrade(exec) {
    checkGrade(sign);
	checkGrade(exec);
	std::cout << "AForm name constructor called." << std::endl;
    this->_signed = 0;
}

AForm::AForm(AForm const &rhs) : _name(rhs._name), _signGrade(rhs._signGrade), _execGrade(rhs._execGrade) {
    std::cout << "AForm copy constructor called." << std::endl;
    *this = rhs;
}

AForm::~AForm() {
    std::cout << "Form destructor called." << std::endl;
}

AForm& AForm::operator=(AForm const &rhs) {
    std::cout << "AForm assignation operator called." << std::endl;
    if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

std::string const AForm::getName(void) const {
	return this->_name;
}

unsigned int AForm::getSignGrade(void) const {
	return this->_signGrade;
}

unsigned int AForm::getExecGrade(void) const {
	return this->_execGrade;
}

bool AForm::isSigned(void) const {
	return this->_signed;
}

void AForm::checkGrade(unsigned int grade) const {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

void AForm::checkSigning(Bureaucrat const &signee) const {
	if (this->getSignGrade() < signee.getGrade())
		throw AForm::FormCantSign(signee.getName(), this->getName(), "bureaucrat's grade too low.");
}

void AForm::checkExec(Bureaucrat const &signee) const {
	if (this->getExecGrade() < signee.getGrade())
		throw AForm::FormCantExec(signee.getName(), this->getName(), "bureaucrat's grade too low.");
}

void AForm::beSigned(Bureaucrat const &signee) {
	checkSigning(signee);
	if (this->isSigned())
		throw AForm::FormCantSign(signee.getName(), this->getName(), "form is already signed.");
	this->_signed = 1;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low.");
}

const char* AForm::FormCantSign::what() const throw() {
	std::cout << this->_bureaucrat << " couldn't sign " << this->_form << " because ";
	return (_reason.c_str());
}

const char* AForm::FormCantExec::what() const throw() {
	std::cout << this->_bureaucrat << " couldn't execute " << this->_form << " because ";
	return (_reason.c_str());
}

std::ostream & operator<<(std::ostream &o, AForm const &src) {
	o << src.getName() << "'s infos :"<< std::endl;
	o << "grade required to sign : " << src.getSignGrade() << std::endl;
	o << "grade required to execute : " << src.getExecGrade() << std::endl;
	o << "signed state : " << src.isSigned() << std::endl;
	return o;
}