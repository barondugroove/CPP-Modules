/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 15:01:08 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HumanA_HPP
# define HumanA_HPP
#include "Weapon.hpp"
#include <string>

class HumanA {
	public :
		HumanA(std::string name, Weapon& weaponType);
		~HumanA(void);

		void attack(void);

	private :
		std::string _name;
		Weapon&	_weapon;
};

#endif
