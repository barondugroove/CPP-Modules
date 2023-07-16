/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/16 19:40:12 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

std::string copyFile(char *fileName) {
	std::string buf;
	std::ifstream file;
	std::stringstream str;

	file.open(fileName);
	buf = "";
	if (!file.is_open())
		return (buf);
	str << file.rdbuf();
	buf = str.str();
	if (buf.empty())
		return (buf);
	file.close();
	return (buf);
}

void createDb(std::vector<std::pair<std::string, int> > db, std::string input) {
	std::string date;

	(void)db;
	input.erase(0, input.find("\n"));
	date = input.substr(0, input.find(" "));
	std::cout << date << std::endl;
}

int main(int ac, char **av)
{
	std::string buf;
	std::filebuf input;
	
	if (ac != 2) {
		std::cout << "Wrong number of arguments." << std::endl;
		return 1;
	}
	std::vector<std::pair<std::string, int> > db;
	buf = copyFile(av[1]);
	std::cout << buf << std::endl;
	createDb(db, buf);
	return 0;
}