/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:39:35 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/10 15:00:44 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
	public :
		Weapon(std::string type);
		~Weapon(void);

		const std::string& getType(void) const;
		void setType(std::string weaponType);

	private :
		std::string _type;
};

#endif
