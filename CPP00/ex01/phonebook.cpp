/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:10:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/26 16:43:57 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook(void) {
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
	std::cout << "Utiliser les commandes ci-dessous pour manipuler l'annuaire :" << std::endl;
	std::cout << "	ADD : permet d'ajouter un contact." << std::endl;
	std::cout << "	SEARCH : permet d'afficher un contact précis." << std::endl;
	std::cout << "	EXIT : quitte l'annuaire." << std::endl;
	std::cout << std::endl;
}

void Phonebook::printHelp(void) const {
	std::cout << std::endl;
	std::cout << "Utiliser les commandes ci-dessous pour manipuler l'annuaire :" << std::endl;
	std::cout << "	ADD : permet d'ajouter un contact." << std::endl;
	std::cout << "	SEARCH : permet d'afficher un contact précis." << std::endl;
	std::cout << "	EXIT : quitte l'annuaire." << std::endl;
	std::cout << std::endl;
}

void Phonebook::displayContact(void) const {
	std::cout << "__________________________________________________" << std::endl;
	std::cout << "|           |            |            |           |" << std::endl;
	std::cout << "|   INDEX   | FIRST NAME | LAST NAME  |  NICKNAME |" << std::endl;
	std::cout << "|___________|____________|___________ |___________|" << std::endl;
	std::cout << std::endl;
}

void Phonebook::addContact(void) {
	std::string input;

	std::cout << "Please enter contact first name : ";
	std::getline(std::cin, input);
	this->contacts[0].setFirstName(input);
	std::cout << "Please enter contact last name : ";
	std::getline(std::cin, input);
	this->contacts[0].setLastName(input);
	std::cout << "Please enter contact nick name : ";
	std::getline(std::cin, input);
	this->contacts[0].setNickName(input);
	std::cout << "Please enter contact phone number : ";
	std::getline(std::cin, input);
	this->contacts[0].setPhoneNumber(input);
	std::cout << "Please enter contact darkest secret : ";
	std::getline(std::cin, input);
	this->contacts[0].setDarkestSecret(input);
}

void Phonebook::searchContact(void) const {
	std::string input;

	displayContact();
	for (int i = 0; i < 8; i++)
	{
		std::cout << "| ";
		std::cout << std::setw(10);
		std::cout << contacts[i].getIndex() << "|";
		std::cout << std::setw(10);
		if (contacts[i].getFirstName().length() < 10)
			std::cout << contacts[i].getFirstName() << " |";
		else
		{
			std::cout << contacts[i].getFirstName().erase(9, contacts[i].getFirstName().length());
			std::cout << "." << "|";
		}
		std::cout << std::setw(10);
		std::cout << contacts[i].getLastName() << "|";
		std::cout << std::setw(10);
		std::cout << contacts[i].getNickName() << "|" << std::endl;
	}
}
