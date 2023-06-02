/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:13:43 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/02 16:04:28 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <string>

class MateriaSource : public IMateriaSource {
	public :
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		~MateriaSource();

		MateriaSource &operator=(MateriaSource const &rhs);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);

	protected :
		AMateria*	inventory[4];
};

#endif
