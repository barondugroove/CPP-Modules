/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:50:02 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/31 16:06:06 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
class ICharacter;

class AMateria {
	public :
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual ~AMateria() {}

		AMateria &operator=(AMateria const &rhs);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);

	protected :
		std::string type;
};

#endif
