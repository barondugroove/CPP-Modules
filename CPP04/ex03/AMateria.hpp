/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:17:51 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 16:55:59 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria {
	protected :
		std::string type;

	public :
		AMateria(void);
		AMateria(std::string const & type);
		~AMateria(void);

		AMateria &operator=(AMateria const &rhs);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
