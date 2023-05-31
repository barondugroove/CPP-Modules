/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:28 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/31 15:54:08 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
class ICharacter;

class Ice : public AMateria {
	public :
		Ice(void);
		Ice(Ice const &src);
		~Ice(void);

		Ice &operator=(Ice const &rhs);

		void use(ICharacter &target);
		AMateria* clone(void) const;
};

#endif
