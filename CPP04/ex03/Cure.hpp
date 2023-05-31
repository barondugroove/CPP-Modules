/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:28 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/31 17:25:04 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
class ICharacter;

class Cure : public AMateria {
	public :
		Cure(void);
		Cure(Cure const &src);
		~Cure(void);

		Cure &operator=(Cure const &rhs);

		void use(ICharacter &target);
		AMateria* clone(void) const;
};

#endif
