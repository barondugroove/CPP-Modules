/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:38:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/08 18:28:13 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

std::string replace(std::string buffer, std::string search, std::string replace)
{
	size_t	pos;

	if (search == replace || search.empty() || replace.empty())
		return (buffer);
	pos = buffer.find(search);
	while (pos != std::string::npos)
	{
		buffer.erase(pos, search.length());
		buffer.insert(pos, replace);
		pos = buffer.find(search, pos + replace.size());
	}
	return (buffer);
}

std::string copyFile(char *fileName)
{
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

int main(int ac, char **av)
{
	std::string buf;
	std::string fileName;
	std::ofstream outfile;

	if (ac != 4)
	{
		std::cerr << "Error. Wrong arguments number." << std::endl;
		return (1);
	}
	buf = copyFile(av[1]);
	if (buf.empty())
	{
		std::cerr << "Error." << std::endl;
		return (1);
	}
	buf = replace(buf, av[2], av[3]);
	fileName.append(av[1]);
	fileName.append(".replace");
	outfile.open(fileName.c_str());
	outfile << buf;
	outfile.close();
	return (0);
}
