/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:30:29 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/28 17:05:27 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
	return ;
}

Serializer::Serializer(Serializer const &src) {
	*this = src;
	return ;
}

Serializer::~Serializer(void) {
	return ;
}

Serializer &Serializer::operator=(Serializer const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
