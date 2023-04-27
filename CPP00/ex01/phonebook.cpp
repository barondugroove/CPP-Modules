/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:10:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/27 19:16:54 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook(void) {
	_index = -1;
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}

void Phonebook::printStart(void) const {
	std::cout << std::endl;
	std::cout << "██████╗  ██████╗ ██╗███████╗     █████╗ ███╗   ██╗███╗   ██╗██╗   ██╗" << std::endl;
	std::cout << "╚════██╗██╔════╝███║╚════██║    ██╔══██╗████╗  ██║████╗  ██║██║   ██║" << std::endl;
	std::cout << " █████╔╝███████╗╚██║    ██╔╝    ███████║██╔██╗ ██║██╔██╗ ██║██║   ██║" << std::endl;
	std::cout << " ╚═══██╗██╔═══██╗██║   ██╔╝     ██╔══██║██║╚██╗██║██║╚██╗██║██║   ██║" << std::endl;
	std::cout << "██████╔╝╚██████╔╝██║   ██║      ██║  ██║██║ ╚████║██║ ╚████║╚██████╔╝" << std::endl;
	std::cout << "╚═════╝  ╚═════╝ ╚═╝   ╚═╝      ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝ ╚═════╝" << std::endl;
	std::cout << "                     L'ANNUAIRE DE RECHERCHE                        " << std::endl;
	std::cout << std::endl;
}

void Phonebook::printHelp(void) const {
	std::cout << std::endl;
	std::cout << "Use the commands below to manipulate the phonebook :" << std::endl;
	std::cout << "	ADD: allows you to add a contact." << std::endl;
	std::cout << "	SEARCH: display the contact list in addition to a specific contact." << std::endl;
	std::cout << "	EXIT: exit the phonebook." << std::endl;
	std::cout << std::endl;
}

void Phonebook::displayContact(void) const {
	std::cout << "__________________________________________________" << std::endl;
	std::cout << "|           |            |            |           |" << std::endl;
	std::cout << "|   INDEX   | FIRST NAME | LAST NAME  |  NICKNAME |" << std::endl;
	std::cout << "|___________|____________|___________ |___________|" << std::endl;
	std::cout << std::endl;
}

void Phonebook::setIndex(void) {
	_index++;
	if (_index > 7)
		_index = 0;
	if (!contacts[_index].getFirstName().empty())
		contacts[_index].eraseContact(_index);
}

void Phonebook::addContact(void) {
	std::string input;

	setIndex();
	this->contacts[_index].setFirstName(input);
	this->contacts[_index].setLastName(input);
	this->contacts[_index].setNickname(input);
	this->contacts[_index].setPhoneNumber(input);
	this->contacts[_index].setDarkestSecret(input);
}

void	print_var(std::string str) {
	std::cout << std::setw(10);
	if (str.length() < 10)
		std::cout << str << " |";
	else
	{
		std::cout << str.erase(9, str.length());
		std::cout << "." << "|";
	}
}

void Phonebook::searchContact(void) const {
	std::string input;

	displayContact();
	for (int i = 0; i < 8; i++)
	{
		std::cout << "| ";
		std::cout << std::setw(10);
		std::cout << std::to_string(_index);
		std::cout << "|";
		print_var(contacts[i].getFirstName());
		print_var(contacts[i].getLastName());
		print_var(contacts[i].getNickname());
		std::cout << std::endl;
	}
}
