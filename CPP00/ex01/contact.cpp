/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:19:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/21 19:03:00 by bchabot          ###   ########.fr       */
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

std::string Contact::getFirstName(void) {
	return this->_firstName;
}

void Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}

std::string Contact::getLastName(void) {
	return this->_lastName;
}

void Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

std::string Contact::getNickName(void) {
	return this->_nickname;
}

void Contact::setNickName(std::string nickname) {
	_nickname = nickname;
}
