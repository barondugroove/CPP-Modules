/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/17 17:52:30 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

void createDb(std::vector<std::pair<std::string, int> > db, std::string input) {
	std::string tmp;
	std::ifstream file;

	(void)db;
	//input.erase(0, input.find("\n"));
	tmp = "";
	file.open(input.c_str());
	std::getline(file, tmp, '\n' );
	std::cout << tmp << std::endl;
}

int main(int ac, char **av)
{
	std::string buf;
	std::filebuf input;

	(void)av;	
	(void)ac;
/*	if (ac != 2) {
		std::cout << "Wrong number of arguments." << std::endl;
		return 1;
	}*/
	std::vector<std::pair<std::string, int> > db;
	std::map<std::string, int> dbBitcoin;
	createDb(db, "data.csv");
	return 0;
}