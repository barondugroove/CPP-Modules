/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:07:27 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/14 19:07:44 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <map>

bool	checkFile(const char *fileName);
bool	isValidDate(std::string &dateStr);
bool	isValidValue(std::string &value);
void	createDb(std::map<std::string, float> &db, const std::string &input);
void	searchDb(const std::map<std::string, float> &db, const std::string &input);

#endif
