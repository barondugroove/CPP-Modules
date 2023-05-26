/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:13:12 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/25 11:43:19 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat &operator=(Cat const &rhs);

		void makeSound(void) const;
};

#endif
