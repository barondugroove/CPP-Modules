/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:10:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/21 19:10:46 by bchabot          ###   ########.fr       */
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

void Phonebook::add_contact(void) {
	std::string input;

	std::cout << "Please enter contact first name." << std::endl;
	std::cin >> input;
	this->contacts[0].setFirstName(input);
	std::cout << "Please enter contact last name." << std::endl;
	std::cin >> input;
	this->contacts[0].setLastName(input);
	std::cout << contacts->getFirstName();
//	std::cout << contacts[0].lst_name << std::endl;
//	std::cout << contacts[0].nickname << std::endl;
}

void Phonebook::print_help(void) {
	std::cout << "       3617 ANNU       " << std::endl;
	std::cout << "L'ANNUAIRE DE RECHERCHE" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Utiliser les commandes ci-dessous pour manipuler l'annuaire :" << std::endl;
	std::cout << "	ADD : permet d'ajouter un contact." << std::endl;
	std::cout << "	SEARCH : permet d'afficher un contact précis." << std::endl;
	std::cout << "	EXIT : quitte l'annuaire." << std::endl;
	std::cout << std::endl;
}
