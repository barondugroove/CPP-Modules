/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:11:00 by bchabot           #+#    #+#             */
/*   Updated: 2023/04/26 16:43:48 by bchabot          ###   ########.fr       */
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

		std::string getFirstName(void) const;
		void setFirstName(std::string firstName);
		std::string getLastName(void) const;
		void setLastName(std::string lastName);
		std::string getNickName(void) const;
		void setNickName(std::string nickName);
		std::string getPhoneNumber(void) const;
		void setPhoneNumber(std::string phoneNumber);
		std::string getDarkestSecret(void) const;
		void setDarkestSecret(std::string darkestSecret);
		int getIndex(void) const;

	private :
		int	_index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
