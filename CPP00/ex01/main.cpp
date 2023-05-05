/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:11:14 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/05 14:30:03 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>

bool valid_command(std::string command)
{
	if (!command.compare("ADD") || !command.compare("HELP")
		|| !command.compare("SEARCH") || !command.compare("EXIT") || command.empty())
		return (true);
	return (false);
}

int	main(int ac, char **av)
{
	Phonebook minitel;
	std::string input;

	(void)av;
	if (ac != 1)
	{
		std::cerr << "No argument required, try again.";
		return (1);
	}
	minitel.printStart();
	while (std::cin)
	{
		std::cout << "Type a command : ";
		std::getline(std::cin, input);
		if (!valid_command(input))
			std::cerr << "Command " << input << " does not exist. Type HELP to see useful commands." << std::endl;
		else if (input == "ADD")
			minitel.addContact();
		else if (input == "SEARCH")
			minitel.searchContact();
		else if (input == "HELP")
			minitel.printHelp();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
