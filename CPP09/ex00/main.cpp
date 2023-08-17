/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/17 16:14:53 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

bool	checkFile(const char *fileName) {
	std::string tmp;
	std::ifstream file(fileName);

	if (!file.good()) {
		std::cout << "Error could not open file " << fileName << "." << std::endl;
		return false;
	}
	if (file.peek() == EOF) {
		std::cout << "Error, file " << fileName << " is empty." << std::endl;
		return false;
	}
	return true;
}

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error could not open file." << std::endl;
		return 1;
	}
	if (!checkFile("data.csv") || !checkFile(av[1]))
		return 1;
	std::map<std::string, float> dbBitcoin;
	BitcoinExchange::createDb(dbBitcoin, "data.csv");
	if (dbBitcoin.empty()) {
		std::cerr << "Error. Database is empty." << std::endl;
		return 1;
	}
	BitcoinExchange::searchDb(dbBitcoin, av[1]);
	return 0;
}
