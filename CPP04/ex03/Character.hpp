/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:59:12 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/31 16:47:06 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CPP
# define CHARACTER_CPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		~Character(void);

		Character &operator=(Character const &rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private :
		std::string	_name;
		AMateria*	_inventory[4];
};

#endif
