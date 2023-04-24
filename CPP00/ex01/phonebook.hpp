/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:10:41 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/23 14:30:28 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook {

	public :
		Phonebook (void);
		~Phonebook (void);

		void	addContact(void);
		void	searchContact(void) const;
		void	displayContact(void) const;

		void	printStart(void) const;
		void	printHelp(void) const;

	private :
		Contact contacts[8];
};

#endif
