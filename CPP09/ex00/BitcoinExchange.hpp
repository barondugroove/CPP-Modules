/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:07:27 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/17 18:27:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>

class BitcoinExchange {
	public :
		static void	createDb(std::map<std::string, float> &db, const std::string &input);
		static void	searchDb(const std::map<std::string, float> &db, const std::string &input);

	private :
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &rhs);
};

#endif
