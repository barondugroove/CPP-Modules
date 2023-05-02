/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:10:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/02 18:18:25 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>


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

void Phonebook::displayTab(void) const {
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void	Phonebook::printVar(std::string str) const {
	if (str.length() < 10)
	{
		std::cout << std::setw(10);
		std::cout << str << "|";
	}
	else
	{
		std::cout << std::setw(9);
		std::cout << str.erase(9, str.length());
		std::cout << "." << "|";
	}
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

void	Phonebook::printContact(int start, int end) const {
	for (int i = start; i < end; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i + 1;
		std::cout << "|";
		printVar(contacts[i].getFirstName());
		printVar(contacts[i].getLastName());
		printVar(contacts[i].getNickname());
		std::cout << std::endl;
	}
}

void Phonebook::displayContact(void) const {
	std::string input;
	int	index;

	while (std::cin)
	{
		std::cout << "Enter the index of the contact you want to display : ";
		std::getline(std::cin, input);
		index = atoi(input.c_str());
		if ((input.empty() || index > 8 || index < 1))
			std::cout << "Wrong index, please provide a number betweem 1 and 8." << std::endl;
		else if (contacts[index - 1].getFirstName().empty())
		{
			std::cout << "Contact n°" << index << " is empty." << std::endl;
			break ;
		}
		else
		{
			std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
			printContact(index - 1, index);
			std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
			break ;
		}
	}
}

void Phonebook::searchContact(void) const {
	std::string input;

	displayTab();
	printContact(0, 8);
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	displayContact();
}
