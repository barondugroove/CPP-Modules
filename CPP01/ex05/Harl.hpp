/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:28:24 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/08 19:50:42 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <string>

class Harl {

	public :
		Harl(void);
		~Harl(void);

		void complain(std::string level);

	private :
		void (Harl::*func[4])(void);
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
