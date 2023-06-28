/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:26:56 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/28 16:20:23 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "data.h"
#include <stdint.h>

class Serializer {
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	
	private :
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);
		
		Serializer &operator=(Serializer const &rhs);
};

#endif