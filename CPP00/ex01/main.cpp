/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:11:14 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/24 10:39:32 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>

bool valid_command(std::string command)
{
	if (!command.compare("ADD") || !command.compare("HELP") 
		|| !command.compare("SEARCH") || !command.compare("EXIT"))
		return (true);
	return (false);
}

int	main(void)
{
	Phonebook minitel;
	std::string input;

	minitel.printStart();
	while (1)
	{
		std::cout << "Entrez une commande : ";
		std::getline(std::cin, input);
		if (!valid_command(input) && !input.empty())
			std::cout << "Cette commande n'existe pas. Tapez HELP pour voir les commandes existantes." << std::endl;
		else if (input == "ADD")
			minitel.addContact();
		else if (input == "SEARCH")
			minitel.displayContact();
		else if (input == "HELP")
			minitel.printHelp();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
