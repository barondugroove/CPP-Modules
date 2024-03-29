/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/06 11:53:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	int		nbr = 4;
	Animal *zoo[nbr];

	for (int i = 0; i < nbr; i++)
	{
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
		zoo[i]->makeSound();
		std::cout << std::endl;
	}
	for (int i = 0; i < nbr; i++)
		delete zoo[i];

	std::cout << std::endl;
	Cat *pussInBoots = new Cat();
	Cat *garfield = new Cat();
	Dog *milou = new Dog();
	Dog *pluto = new Dog();
	std::cout << std::endl;

	*garfield = *pussInBoots;
	*pluto = *milou;

	std::cout << std::endl;
	pussInBoots->setIdeas("PEE");
	garfield->setIdeas("I HATE MONDAYS");
	std::cout << "Puss In Boots : " << pussInBoots->getIdeas(0);
	std::cout << " || Garfield : " << garfield->getIdeas(0) << std::endl;
	std::cout << "Garfield : " << garfield->getIdeas(100000000) << std::endl;
	pluto->setIdeas("EAT");
	pluto->setIdeas("SLEEP");
	milou->setIdeas("BARK");
	milou->setIdeas("BARK");
	milou->setIdeas("BITE");
	int i = 0;
	while (!pluto->getIdeas(i).empty() || !milou->getIdeas(i).empty())
	{
		std::cout << "Milou : " << milou->getIdeas(i);
		std::cout << " || Pluto : " << pluto->getIdeas(i) << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "DESTRUCTOR MESSAGES" << std::endl;
	delete(pussInBoots);
	delete(garfield);
	delete(milou);
	delete(pluto);
	return (0);
}
