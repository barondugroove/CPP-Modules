/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 15:53:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int ac, char **av)
{
	Harl harl;

	if (ac == 2)
	{
		std::cout << "Examiner tests :" << std::endl;
		harl.complain(atoi(av[1]));
	}
	std::cout << std::endl;
	std::cout << "Personal tests :" << std::endl;
	harl.complain(1);
	harl.complain(50);
	harl.complain(3);
	return (0);
}
