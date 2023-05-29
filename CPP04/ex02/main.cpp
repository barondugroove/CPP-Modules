/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 14:11:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brains.hpp"
#include <iostream>

int main()
{
	int		nbr = 4;
	AAnimal *zoo[nbr];
	// Can't instantiate cause AAnimal is an abstract class.
	//AAnimal *test = AAnimal();

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
	Cat *pussInboots = new Cat();
	Cat *garfield = new Cat();
	Dog *milou = new Dog();
	Dog *pluto = new Dog();
	std::cout << std::endl;

	*garfield = *pussInboots;
	*pluto = *milou;

	std::cout << std::endl;
	pussInboots->setIdeas("PEE");
	garfield->setIdeas("I HATE MONDAYS");
	std::cout << "Puss In Boots : " << pussInboots->getIdeas(0);
	std::cout << " || Garfield : " << garfield->getIdeas(0) << std::endl;
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
	delete(pussInboots);
	delete(garfield);
	delete(milou);
	delete(pluto);

	return (0);
}
