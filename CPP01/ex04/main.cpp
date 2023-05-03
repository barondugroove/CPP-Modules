/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:38:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/03 17:11:22 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void	search_replace(char **args)
{
	std::string buffer;

	std::ifstream file(args[0], std::ifstream::binary);
	if (file)
	{
		std::cout << "LOl" << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac == 4)
		search_replace(av + 1);
	return (0);
}
