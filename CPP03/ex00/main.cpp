/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 15:07:53 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	ClapTrap clapTrap("ClapTrap");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3;
	clapTrap3 = clapTrap2;

	clapTrap.attack("target");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(10);
	return (0);
}
