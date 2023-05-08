/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/08 19:50:22 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
	{
		std::cerr << "Error. Wrong arguments number." << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}
