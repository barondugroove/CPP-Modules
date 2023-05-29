/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:13:12 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/25 17:40:37 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

#include "AAnimal.hpp"
#include "Brains.hpp"

class Cat : public AAnimal {
	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat &operator=(Cat const &rhs);

		void makeSound(void) const;
		std::string getIdeas(int index) const;
		void setIdeas(std::string idea);

	private :
		Brains *_brain;
};

#endif