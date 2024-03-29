/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:15:08 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/02 16:31:31 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void	megaphone(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
		std::cout << (unsigned char)std::toupper(str[i]);
	return ;
}

int	main(int ac, char **av)
{
	int	i;
	std::string str;

	i = 1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (av[i])
		{
			str = av[i++];
			megaphone(str);
		}
	}
	std::cout << std::endl;
	return (0);
}
