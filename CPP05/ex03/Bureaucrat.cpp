/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:56:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/08 18:02:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <exception>

Bureaucrat::Bureaucrat(void) : _name("intern"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade) : _name("intern"), _grade(grade) {
	check_grade(grade);
	std::cout << "Bureaucrat grade parametric constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
	check_grade(grade);
	std::cout << "Bureaucrat name and grade parametric constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}
	
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

std::string const Bureaucrat::getName(void) const {
	return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::check_grade(int grade) const {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incrementGrade(void) {
	check_grade(this->_grade - 1);
	this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
	check_grade(this->_grade + 1);
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low.");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const &src) {
    o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return o;
}

void	Bureaucrat::signForm(AForm &form) const {
	form.checkSigning(this->getGrade());
	if (form.isSigned())
		throw AForm::AFormAlreadySigned();
	form.beSigned(*this);
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm &form) const {
	form.checkSigning(this->getGrade());
	if (!form.isSigned())
		throw AForm::FormNotSigned();
	form.execute(*this);
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}