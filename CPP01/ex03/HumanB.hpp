/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 15:00:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HumanB_HPP
# define HumanB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
	public :
		HumanB(std::string name);
		~HumanB(void);

		void attack(void);
		void setWeapon(Weapon& weaponType);

	private :
		std::string _name;
		Weapon* _weapon;
};

#endif
