/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:29:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/17 18:22:28 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#define INT_OVERFLOW 2147483648

#include <stack>
#include <string>
#include <iostream>

class RPN {
	public :
		static void	rpn(std::string &str);

	private :
		RPN();
		RPN(const RPN &src);
		~RPN();

		RPN &operator=(RPN const &rhs);
};

#endif
