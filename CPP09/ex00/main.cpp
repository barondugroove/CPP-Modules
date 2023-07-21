/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:16 by bchabot           #+#    #+#             */
/*   Updated: 2023/07/21 15:45:26 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip> 
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <regex.h>


bool isValidDateFormat(const char* dateStr) {
    regex_t regex;
    int reti = regcomp(&regex, "^[0-9]{4}-[0-9]{2}-[0-9]{2}$", REG_EXTENDED);

    if (reti) {
        std::cerr << "Error compiling regex\n";
        return false;
    }

    reti = regexec(&regex, dateStr, 0, NULL, 0);
    regfree(&regex);

    return (reti == 0);
}

bool isValidDate(const char* dateStr) {
    if (!isValidDateFormat(dateStr)) {
		return false;
    }

    int year, month, day;
    std::sscanf(dateStr, "%d-%d-%d", &year, &month, &day);

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return false; // Invalid range

    // Check February's day range considering leap years
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && (day > 29 || (day > 28 && !isLeapYear)))
        return false; // Invalid day for February

    // Check day based on month and year
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month - 1])
        return false; // Invalid day for the given month and year

    // Using mktime to check if the date is valid
    std::tm tm = {};
    tm.tm_year = year - 1900; // Years since 1900
    tm.tm_mon = month - 1;    // Months since January (0-based)
    tm.tm_mday = day;         // Day of the month

    std::mktime(&tm);

    // mktime adjusts the input values if they are out of range
    // If the adjusted values differ from the input, then the date is invalid
    return (tm.tm_year == year - 1900 &&
            tm.tm_mon == month - 1 &&
            tm.tm_mday == day);
}

bool isValidValue(std::string &value) {
	double	test = strtod(value.c_str(), NULL);
	if (test < 0 || test > INT_MAX)
		return false;
	return true;
}

void createDb(std::map<std::string, float> &db, const std::string &input) {
	std::string tmp;
	std::ifstream file;
	
	file.open(input.c_str());
	while (std::getline(file, tmp))
		if (isdigit(*tmp.begin()))
		{
			int coma = tmp.find(",", 0);
			std::string date = tmp.substr(0, coma);
			std::string valueS = tmp.substr(coma + 1, tmp.size() - coma);
			float value = strtof(valueS.c_str(), NULL);
			if (isValidDate(date.c_str()) && isValidValue(valueS) && coma != -1)
				db.insert(std::pair<std::string, float>(date, value));
		}
}

int main(int ac, char **av)
{
	std::string buf;
	std::filebuf input;

	(void)av;	
	(void)ac;
/*	if (ac != 2) {
		std::cout << "Error could not open file." << std::endl;
		return 1;
	}*/
	std::map<std::string, float> dbBitcoin;
	createDb(dbBitcoin, "data2.csv");
	for (std::map<std::string, float>::iterator ptr = dbBitcoin.begin(); ptr != dbBitcoin.end(); ptr++)
		std::cout << ptr->first << " | " << ptr->second << std::endl;
	return 0;
}