/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:07:27 by bchabot           #+#    #+#             */
/*   Updated: 2023/08/17 22:24:06 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <climits>
#include <cstdlib>
#include <fstream>
#include <sstream>

static bool	isValidDate(std::string &dateStr) {
	std::istringstream iss(dateStr);
	int year, month, day;
	char	separator1, separator2;
	bool	isValid = true;

	if (dateStr < "2009-01-03")
		isValid = false;

	// Try to extract the components using the specified format
	if (!(iss >> year >> separator1 >> month >> separator2 >> day)) {
		isValid = false;
	}
	// Check if the extraction was successful and separators are correct
	if (separator1 != '-' || separator2 != '-' || iss.peek() != EOF) {
		isValid = false;
	}

	if (year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		isValid = false;

	// Check Days in months including February's day range considering leap years
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0);
	const int daysInMonth[] = {31, 28 + isLeapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1]) {
		isValid = false;
	}
	return isValid;
}

static bool isValidValue(std::string &valueStr, double value) {
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

void BitcoinExchange::createDb(std::map<std::string, float> &db, const std::string &input) {
	std::string tmp;
	std::ifstream file(input.c_str());
	std::string date;
	std::string valueS;
	float value = 0;

	std::getline(file, tmp);
	if (tmp != "date,exchange_rate") {
		return;
	}
	while (std::getline(file, tmp))
	{
		if (isdigit(tmp[0])) {
			int comma = tmp.find(',', 0);
			date = tmp.substr(0, comma);
			valueS = tmp.substr(comma + 1, tmp.size() - comma);
			value = strtof(valueS.c_str(), NULL);
			if (comma != -1 && isValidDate(date) && isValidValue(valueS, INT_MAX))
				db.insert(std::pair<std::string, float>(date, value));
		}
	}
}

static bool	checkInputs(int comma ,std::string &date, std::string &value) {
	if (date.empty() || value.empty())
		return false;

	if (comma == -1 || !isValidDate(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (!isValidValue(value, 1000))
		return false;
	return true;
}

void	BitcoinExchange::searchDb(const std::map<std::string, float> &db, const std::string &input) {
	std::string tmp;
	std::ifstream file(input.c_str());
	std::string date;
	std::string valueS;
	float value = 0;

	std::getline(file, tmp);
	if (tmp != "date | value") {
		std::cerr << "Error. Input file is erroneous." << std::endl;
		return;
	}
	while (std::getline(file, tmp))
	{
		if (isdigit(tmp[0])) {
			int comma = tmp.find(" | ", 0);
			date = tmp.substr(0, comma);
			valueS = tmp.substr(comma + 3, tmp.size() - comma);
			value = strtof(valueS.c_str(), NULL);

			// Use upper_bound to check if the date exists in the database
			std::map<std::string, float>::const_iterator it = db.upper_bound(date);
			if (checkInputs(comma, date, valueS))
			{
				if (it != db.begin()) {
					it--;
					std::cout << date << " => " << value << " = " << value * it->second << std::endl;
				}
				else
					std::cerr << "Error: date outside of database range." << std::endl;
			}
		}
		else
			std::cout << "Error: bad input => " << tmp << std::endl;
	}
}

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void)rhs;
	return *this;
}
