/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:07:40 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/19 13:46:24 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <iostream>

Form::Form() : _name("Form"), _signGrade(1), _execGrade(1) {
    std::cout << "Form default constructor called." << std::endl;
    this->_signed = 0;
}

Form::Form(std::string name) : _name(name), _signGrade(1), _execGrade(1) {
    std::cout << "Form name constructor called." << std::endl;
    this->_signed = 0;
}

Form::Form(std::string name, unsigned int sign, unsigned int exec) : _name(name), _signGrade(sign), _execGrade(exec) {
	checkGrade(sign);
	checkGrade(exec);
	std::cout << "Form name constructor called." << std::endl;
    this->_signed = 0;
}

Form::Form(unsigned int sign, unsigned int exec) : _name("Form"), _signGrade(sign), _execGrade(exec) {
    checkGrade(sign);
	checkGrade(exec);
	std::cout << "Form name constructor called." << std::endl;
    this->_signed = 0;
}

Form::Form(Form const &rhs) : _name(rhs._name), _signGrade(rhs._signGrade), _execGrade(rhs._execGrade) {
    std::cout << "Form copy constructor called." << std::endl;
    *this = rhs;
}

Form::~Form() {
    std::cout << "Form destructor called." << std::endl;
}

Form& Form::operator=(Form const &rhs) {
    std::cout << "Form assignation operator called." << std::endl;
    if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form grade is too low.");
}

const char* Form::FormCantSign::what() const throw() {
	std::cout << this->_bureaucrat << " couldn't sign " << this->_form << " because ";
	return (_reason.c_str());
}

std::ostream & operator<<(std::ostream &o, Form const &src) {
	o << src.getName() << "'s infos :"<< std::endl;
	o << "grade required to sign : " << src.getSignGrade() << std::endl;
	o << "grade required to execute : " << src.getExecGrade() << std::endl;
	o << "signed state : " << src.isSigned() << std::endl;
	return o;
}

std::string const Form::getName(void) const {
	return this->_name;
}

unsigned int Form::getSignGrade(void) const {
	return this->_signGrade;
}

unsigned int Form::getExecGrade(void) const {
	return this->_execGrade;
}

bool Form::isSigned(void) const {
	return this->_signed;
}

void Form::checkGrade(unsigned int grade) const {
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

void Form::checkSigning(Bureaucrat const &signee) const {
	if (this->getSignGrade() < signee.getGrade())
		throw Form::FormCantSign(signee.getName(), this->getName(), "bureaucrat's grade too low.");
}

void Form::beSigned(Bureaucrat const &signee) {
	checkSigning(signee);
	if (this->isSigned())
		throw Form::FormCantSign(signee.getName(), this->getName(), "form is already signed.");
	this->_signed = 1;
}