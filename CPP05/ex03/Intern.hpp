/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:00:40 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/09 16:48:38 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	public :
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern& operator=(Intern const &rhs);

		AForm* makeForm(std::string const & name, std::string const & target);

		class NoContract : public std::exception {
			public :
				virtual const char* watch() const throw();
		};
};

#endif