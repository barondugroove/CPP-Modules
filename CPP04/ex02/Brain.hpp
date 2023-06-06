/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:51:13 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/06 11:48:53 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
	public :
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);

		Brain &operator=(Brain const &rhs);

		std::string getIdeas(int index) const;
		void setIdeas(std::string idea);

	private :
		std::string ideas[100];
};

#endif
