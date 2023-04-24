/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:10:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/23 20:07:33 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

Phonebook::Phonebook(void) {
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}

void Phonebook::addContact(void) {
	std::string input;

	std::cout << "Please enter contact first name : ";
	std::getline(std::cin, input);
	this->contacts[0].setFirstName(input);
	std::cout << "Please enter contact last name : ";
	std::getline(std::cin, input);
	this->contacts[0].setLastName(input);
}

void Phonebook::searchContact(void) const {
	std::string input;
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
	std::cout << "_________________________________________________" << std::endl;
	std::cout << "|           |            |           |          |" << std::endl;
	std::cout << "|   INDEX   | FIRST NAME | LAST NAME | NICKNAME |" << std::endl;
	std::cout << "|___________|____________|___________|__________|" << std::endl;
	std::cout << std::endl;
}
