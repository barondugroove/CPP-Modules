/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:05:30 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 19:26:59 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {
    public:
        Animal(void);
        Animal(Animal const &src);
        virtual ~Animal(void);

        Animal &operator=(Animal const &rhs);

        std::string getType(void) const;

        void makeSound(void) const;

    protected :
        std::string type;
};

#endif