/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:34:53 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/05 15:12:17 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"

int main() {
    try {
		std::vector<int> myvector (50, 4);
		easyfind(myvector, 1);
    }
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	try {
		std::list<int> mylist (50, 4);
		easyfind(mylist, 4);
    }
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}