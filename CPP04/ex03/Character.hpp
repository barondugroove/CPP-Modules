/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:40:17 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 17:04:48 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class Character : public ICharacter {
	public :
		Character();
		Character(const std::string &name);
		~Character();

		Character &operator=(Character const &rhs);

	private :
		std::string _name;
		Materia 	inventory[4];
};

#endif
