/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:38 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/02 21:52:22 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie {
	public :
		Zombie(void);
		~Zombie(void);

		void announce(void) const;
		void setName(std::string name);

	private :
		std::string _name;
};

#endif
