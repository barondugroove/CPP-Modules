/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:47:40 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 14:57:04 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		N = 1;
	Zombie *hord = new Zombie[N];

	for (int i = 0; i < N; i++)
		hord[i].setName(name);
	return (hord);
}
