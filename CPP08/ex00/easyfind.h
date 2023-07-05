/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:35:18 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/05 15:11:25 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <list>
#include <exception>
#include <iostream>

class NotElementFound : public std::exception {
	public :
		virtual const char* what() const throw() {
			return ("Element not found.");
		};
};

template<typename T>
void easyfind(T const &content, int const nbr) {
	if (std::find(content.begin(), content.end(), nbr) == content.end())
		throw NotElementFound();
	std::cout << "Element " << nbr << " found." << std::endl;
}