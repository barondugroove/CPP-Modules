/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brains.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:51:13 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 19:55:49 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINS_HPP
# define BRAINS_HPP

#include <string>

class Brains {
    public :
        Brains(void);
        Brains(Brains const &src);
        ~Brains(void);

        Brains &operator=(Brains const &rhs);

        std::string ideas[100];
};

#endif