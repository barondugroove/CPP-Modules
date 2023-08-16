/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/16 11:49:01 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#define INT_OVERFLOW 2147483648

#include <stack>
#include <string>
#include <iostream>

bool	checkErrors(std::string &str);
int		isOperator(char &c);
void	calc(std::stack<char> &calculus, int i);
void 	rpn(std::string &str);

#endif
