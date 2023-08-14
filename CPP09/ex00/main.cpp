/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/14 19:11:23 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Error could not open file." << std::endl;
		return 1;
	}
	if (!checkFile("data.csv") || !checkFile(av[1]))
		return 1;
	std::map<std::string, float> dbBitcoin;
	createDb(dbBitcoin, "data.csv");
	searchDb(dbBitcoin, av[1]);
	return 0;
}
