/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:07:27 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/16 12:47:35 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <climits>
#include <cstdlib>
#include <fstream>
#include <sstream>

bool	checkFile(const char *fileName) {
	std::string tmp;
	std::ifstream file(fileName);

	if (!file.good()) {
		std::cout << "Error could not open file " << fileName << "." << std::endl;
		return false;
	}
	if (file.peek() == EOF) {
		std::cout << "Error, file " << fileName << " is empty." << std::endl;
		return false;
	}
	return true;
}

bool isValidDate(std::string &dateStr) {
	std::istringstream iss(dateStr);
	int year, month, day;
	char separator1, separator2;

	if (dateStr < "2009-01-03")
		return false;

	// Try to extract the components using the specified format
	if (!(iss >> year >> separator1 >> month >> separator2 >> day)) {
		return false;
	}

	// Check if the extraction was successful and separators are correct
	if (separator1 != '-' || separator2 != '-' || iss.peek() != EOF) {
		return false;
	}

	if (year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	// Check Days in months including February's day range considering leap years
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0);
	const int daysInMonth[] = {31, 28 + isLeapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1]) {
		return false;
	}
	return true;
}

bool isValidValue(std::string &valueStr, double value) {
	char	*ptr;
	double	test = strtod(valueStr.c_str(), &ptr);
	if (*ptr != '\0') {
		if (value == 1000)
			std::cout << "Error: not a number." << std::endl;
		return false;
	}
	if (test < 0) {
		if (value == 1000)
			std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (test > value) {
		if (value == 1000)
			std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void createDb(std::map<std::string, float> &db, const std::string &input) {
	std::string tmp;
	std::ifstream file(input.c_str());

	std::getline(file, tmp);
	while (std::getline(file, tmp))
	{
		int coma = tmp.find(',', 0);
		std::string date = tmp.substr(0, coma);
		std::string valueS = tmp.substr(coma + 1, tmp.size() - coma);
		float value = strtof(valueS.c_str(), NULL);
		if (isValidDate(date) && isValidValue(valueS, INT_MAX) && coma != -1)
			db.insert(std::pair<std::string, float>(date, value));
	}
}

void	searchDb(const std::map<std::string, float> &db, const std::string &input) {
	std::string tmp;
	std::ifstream file(input.c_str());

	std::getline(file, tmp);
	while (std::getline(file, tmp))
	{
		int coma = tmp.find("|", 0);
		std::string date = tmp.substr(0, coma - 1);
		std::string valueS = tmp.substr(coma + 1, tmp.size() - coma);
		float value = strtof(valueS.c_str(), NULL);

		// Use upper_bound to check if the date exists in the database
		std::map<std::string, float>::const_iterator it = db.upper_bound(date);
		if (isValidDate(date) && isValidValue(valueS, 1000) && coma != -1)
		{
			if (it != db.begin()) {
				it--;
			}
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
		else if (!isValidDate(date))
			std::cout << "Error: bad input => " << date << std::endl;
	}
}
