/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:40:07 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/28 17:05:15 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <string>
#include <iostream>

struct Data {
	int integer;
	std::string string;
	float flt;
	double dbl;
};