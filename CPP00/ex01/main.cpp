/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:11:14 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/21 19:18:08 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	Phonebook minitel;
	std::string input;

	std::cout << "       3617 ANNU       " << std::endl;
	std::cout << "L'ANNUAIRE DE RECHERCHE" << std::endl;
	std::cout << std::endl;
	std::cout << "Utiliser les commandes ci-dessous pour manipuler l'annuaire :" << std::endl;
	std::cout << "	ADD : ajoute un contact." << std::endl;
	std::cout << "	SEARCH : affiche un contact précis." << std::endl;
	std::cout << "	HELP : affiche les commandes utiles." << std::endl;
	std::cout << "	EXIT : quitte l'annuaire." << std::endl;
	std::cout << std::endl;
	while (1)
	{
		std::cout << "Tape des choses.";
		std::cin >> input;
		if (input.empty())
			continue ;
		if (input == "ADD")
			minitel.add_contact();
		else if (input == "HELP")
			minitel.print_help();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
