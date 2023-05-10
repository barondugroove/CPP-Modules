/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:38:22 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 15:43:38 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "string addr is : " << &string << std::endl;
	std::cout << "stringPTR addr is : " << stringPTR << std::endl;
	std::cout << "stringREF addr is : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "string value is : " << string << std::endl;
	std::cout << "stringPTR value is : " << *stringPTR << std::endl;
	std::cout << "stringREF value is : " << stringREF << std::endl;
}
