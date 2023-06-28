/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:33:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/28 18:48:47 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cmath>
#include <exception>
#include <stdint.h>

Base* generate(void) {
	Base	*base;
	int		nbr;
	
	srand(clock());
	nbr = ((rand() % 3) + 1);
	switch (nbr)
	{
		case 1:
			base = new A();
		break;

		case 2:
			base = new B();
		break;

		case 3:
			base = new C();
		break;
	}
	return base;
}

void identify(Base *p) {
	Base *base = dynamic_cast<A*>(p);
	if (base)
		std::cout << "p point to an A object." << std::endl;
	Base *base2 = dynamic_cast<B*>(p);
	if (base2)
		std::cout << "p point to an B object." << std::endl;
	Base *base3 = dynamic_cast<C*>(p);
	if (base3)
		std::cout << "p point to an C object." << std::endl;
}

void identify(Base &p) {
	try {
		Base &base = dynamic_cast<A&>(p);
		(void)base;
		std::cout << "p point to an A object." << std::endl;
	}
	catch (std::exception &e) {}
	
	try {
		Base &base = dynamic_cast<B&>(p);
		(void)base;
		std::cout << "p point to an B object." << std::endl;
	}
	catch (std::exception &e) {}
	
	try {
		Base &base = dynamic_cast<C&>(p);
		(void)base;
		std::cout << "p point to an C object." << std::endl;
	}
	catch (std::exception &e) {}
}

int main(void) {
	Base *base = generate();
	Base &base2 = *base;
	Base *bases[5];
	for (int i = 0; i < 5; i++)
	{
		bases[i] = generate();
		identify(bases[i]);
		identify(*bases[i]);
		delete bases[i];
	}
	identify(base);
	identify(base2);
	delete (base);
	return 0;
}