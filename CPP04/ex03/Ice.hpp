/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:59:00 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 16:10:46 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Ice : public AMateria {
	public :
		Ice(void);
		Ice(std::string const &type);
		~Ice(void);

		Ice &operator=(Ice const &rhs);
		AMateria* clone(Ice const &rhs) const;
		void use(ICharacter &target);

	private :
};

#endif
