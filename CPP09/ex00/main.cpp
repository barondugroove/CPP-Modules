/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/16 11:03:20 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error could not open file." << std::endl;
		return 1;
	}
	if (!checkFile("data.csv") || !checkFile(av[1]))
		return 1;
	std::map<std::string, float> dbBitcoin;
	createDb(dbBitcoin, "data.csv");
	if (dbBitcoin.empty()) {
		std::cerr << "Error. Database is empty." << std::endl;
		return 1;
	}
	searchDb(dbBitcoin, av[1]);
	return 0;
}
