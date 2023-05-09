/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/09 12:01:06 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	Harl harl;

	if (ac == 2)
	{
		std::cout << "Examinor tests :" << std::endl;
		harl.complain(atoi(av[1]));
	}
	std::cout << "Personal tests :" << std::endl;
	harl.complain(2);
	harl.complain(50);
	return (0);
}
