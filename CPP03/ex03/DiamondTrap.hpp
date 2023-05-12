/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:24:44 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 18:31:04 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &src);
        ~DiamondTrap(void);

        DiamondTrap &operator=(DiamondTrap const &rhs);
        
        void whoAmI(void);

    private:
        std::string _name;
};

#endif