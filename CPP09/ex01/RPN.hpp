/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/08 19:05:21 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

void	checkErrors(std::string &str);
int		isOperator(char &c);
void	calc(std::stack<char> &calculus, int i);
void 	rpn(std::string &str);

#endif