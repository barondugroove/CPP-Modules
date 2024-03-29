/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:39:15 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/02 16:15:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	std::cout << "Constructor messages :" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	AMateria* tmp2;
	ICharacter* bob = new Character("bob");

	std::cout << std::endl << "Test messages :" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	delete(tmp2);

	std::cout << std::endl << "Destructor messages :" << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}
