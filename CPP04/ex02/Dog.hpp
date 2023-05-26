/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:13:12 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/25 17:40:47 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brains.hpp"

class Dog : public AAnimal {
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog &operator=(Dog const &rhs);

		void makeSound(void) const;
		std::string getIdeas(int index) const;
		void setIdeas(std::string idea);

	private :
		Brains *_brain;
};

#endif
