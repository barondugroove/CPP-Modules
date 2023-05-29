/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:00:05 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/29 16:10:08 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Cure : public AMateria {
	public :
		Cure(void);
		Cure(std::string const & type);
		~Cure(void);

		Cure &operator=(Cure const &rhs);
		AMateria* clone(Cure const &rhs) const;
		void use(ICharacter &target);

	private :
};

#endif
