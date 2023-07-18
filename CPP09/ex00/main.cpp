/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/18 16:28:43 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iomanip> 
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

void createDb(std::map<std::string, float> db, std::string input) {
	std::string tmp;
	std::ifstream file;
	
	file.open(input.c_str());
	while (std::getline(file, tmp))
		if (isdigit(*tmp.begin()))
		{
			int coma = tmp.find(",", 0);
			std::string date = tmp.substr(0, coma);
			std::string valueS = tmp.substr(coma + 1, tmp.size() - coma);
			float value = strtof(valueS.c_str(), NULL);
			db.insert(std::pair<std::string, float>(date, value));
		}
	for (std::map<std::string, float>::iterator ptr = db.begin(); ptr != db.end(); ptr++)
		std::cout << ptr->first << " | " << ptr->second << std::endl;
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
	std::map<std::string, float> dbBitcoin;
	createDb(dbBitcoin, "data.csv");
	return 0;
}