/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:28:24 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/09 11:55:55 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <string>

class Harl {

	public :
		Harl(void);
		~Harl(void);

		void complain(int level);

	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
