/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:03 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/25 11:54:11 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << std::endl;
	std::cout << animal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << std::endl;

	cat->makeSound();
	dog->makeSound();
	wrong->makeSound();
	animal->makeSound();
	std::cout << std::endl;

	delete (animal);
	delete (dog);
	delete (cat);
	delete (wrong);
	return (0);
}
