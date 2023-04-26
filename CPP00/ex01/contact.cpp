/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:19:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/26 16:42:40 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

Contact::Contact(void) {
	static int i;

	_index = ++i;
	return ;
}


Contact::~Contact(void) {
	return ;
}

int Contact::getIndex(void) const {
	return this->_index;
}

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

void Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

void Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

std::string Contact::getNickName(void) const {
	return this->_nickname;
}

void Contact::setNickName(std::string nickname) {
	_nickname = nickname;
}

std::string Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	_darkestSecret = darkestSecret;
}
