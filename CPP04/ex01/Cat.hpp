/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:13:12 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/25 16:47:12 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

#include "Animal.hpp"
#include "Brains.hpp"

class Cat : public Animal {
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
