/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:00:40 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 18:22:16 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	public :
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern& operator=(Intern const &rhs);

		AForm* makeForm(std::string const & name, std::string const & target);

		class BadContractTemplate : public std::exception {
			public :
				virtual const char* what() const throw();
		};
};

#endif