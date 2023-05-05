/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:19:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/05 14:30:12 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void Contact::eraseContact(int index) {
	std::cout << "Phonebook is full, adding a new entry will delete contact n° " << index + 1 << "." << std::endl;
	this->_firstName.clear();
	this->_lastName.clear();
	this->_nickname.clear();
	this->_phoneNumber.clear();
	this->_darkestSecret.clear();
	return ;
}

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

void Contact::setFirstName(std::string firstName) {
	while (firstName.empty() && std::cin)
	{
		std::cout << "Please enter contact first name : ";
		std::getline(std::cin, firstName);
		if (firstName.empty() && std::cin)
			std::cerr << "This field can't be empty, please provide a correct name." << std::endl;
		else
			_firstName = firstName;
	}
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

void Contact::setLastName(std::string lastName) {
	while (lastName.empty() && std::cin)
	{
		std::cout << "Please enter contact last name : ";
		std::getline(std::cin, lastName);
		if (lastName.empty() && std::cin)
			std::cerr << "This field can't be empty, please provide a correct name." << std::endl;
		else
			_lastName = lastName;
	}
}

std::string Contact::getNickname(void) const {
	return this->_nickname;
}

void Contact::setNickname(std::string nickname) {
	while (nickname.empty() && std::cin)
	{
		std::cout << "Please enter contact nickname : ";
		std::getline(std::cin, nickname);
		if (nickname.empty() && std::cin)
			std::cerr << "This field can't be empty, please provide a correct entry." << std::endl;
		else
			_nickname = nickname;
	}
}

std::string Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	while (phoneNumber.empty() && std::cin)
	{
		std::cout << "Please enter contact phone number : ";
		std::getline(std::cin, phoneNumber);
		if (phoneNumber.empty() && std::cin)
			std::cerr << "This field can't be empty, please provide a correct number." << std::endl;
		else
			_phoneNumber = phoneNumber;
	}
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}

void Contact::setDarkestSecret(std::string darkestSecret) {

	while (darkestSecret.empty() && std::cin)
	{
		std::cout << "Please enter contact darkest secret : ";
		std::getline(std::cin, darkestSecret);
		if (darkestSecret.empty() && std::cin)
			std::cerr << "This field can't be empty, please provide a correct entry." << std::endl;
		else
			_darkestSecret = darkestSecret;
	}
}
