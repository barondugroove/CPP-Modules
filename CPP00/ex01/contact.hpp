/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:11:00 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/21 18:52:22 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>

class Contact {

	public :
		Contact(void);
		~Contact(void);

		std::string getFirstName(void);
		void setFirstName(std::string firstName);
		std::string getLastName(void);
		void setLastName(std::string LastName);
		std::string getNickName(void);
		void setNickName(std::string NickName);

	private :
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
};

#endif
