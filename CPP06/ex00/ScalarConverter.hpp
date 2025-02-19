#pragma once

#include <iostream>
#include <regex> // for checking what is inside the input string
#include <iomanip> // for std::fixed and std::setprecision
#include <limits> // for data type limits

class ScalarConverter {
	public:
		ScalarConverter(void) = delete; // Canonical
		ScalarConverter(ScalarConverter const & src) = delete; // Canonical
		~ScalarConverter(void) = default; // Canonical

		ScalarConverter & operator=(ScalarConverter const & rhs) = delete; // Canonical

		static void convert(const std::string str);

	private:
		static bool isChar(const std::string &str);
		static bool isInteger(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isSpecialFloat(const std::string& str);
		static void error_all_impossible(void);
		static void convert_special_float(std::string str);
		static void convert_integer(std::string str);
		static void convert_char(std::string str);
		static void convert_float(std::string str);
		static void convert_double(std::string str);
};