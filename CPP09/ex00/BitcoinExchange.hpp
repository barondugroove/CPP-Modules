/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:07:27 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/24 19:13:58 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <map>
#include <fstream>
#include <sstream>

std::ifstream checkFile(const char *fileName);
bool isValidDate(const char* dateStr);
bool isValidValue(std::string &value);
void createDb(std::map<std::string, float> &db, const std::string &input, const char *separator);
void searchDb(const std::map<std::string, float> &db, const std::string &input);

#endif