/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:55:21 by bchabot           #+#    #+#             */
/*   Updated: 2023/05/12 15:04:54 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ClapTrap {
    public :
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap(void);

        ClapTrap &operator=(ClapTrap const &rhs);

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
    private :
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _AttackDamage;
};