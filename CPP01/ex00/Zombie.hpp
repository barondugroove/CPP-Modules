/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:38 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/02 19:32:39 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie {
	public :
		Zombie(std::string name);
		~Zombie(void);

		void announce(void) const;

	private :
		std::string _name;
};

#endif
