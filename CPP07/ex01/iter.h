/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:32:23 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/30 16:45:57 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void f(T content) {
	std::cout << content << std::endl;
}

template<typename T>
void iter(T tab[], int size, void (*f)(T content)) {
	for (int i = 0; i < size; i++)
		(*f)(tab[i]);
}