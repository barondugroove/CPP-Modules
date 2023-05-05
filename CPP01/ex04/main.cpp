/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:38:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/05 14:27:14 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string replace(std::string buffer, std::string search, std::string replace)
{

}

void	copyFile(char **args)
{
	std::string buffer;
	std::ifstream file;

	file.open(args[0]);
	if (file.is_open())
	{
		file >> buffer;
		std::cout << buffer;
	}
	file.close();
	buffer = replace(buffer, args[1], args[2]);
}

int main(int ac, char **av)
{
	if (ac == 4)
		copyFile(av + 1);
	return (0);
}
