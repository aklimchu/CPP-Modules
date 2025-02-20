#pragma once

#include <iostream>
#include <regex> // for checking what is inside the input string
#include <iomanip> // for std::fixed and std::setprecision
#include <limits> // for data type limits

class ScalarConverter {
	public:
		static void convert(const std::string str);

	private:
		ScalarConverter(void) = delete; // Canonical
		ScalarConverter(ScalarConverter const & src) = delete; // Canonical
		~ScalarConverter(void) = default; // Canonical

		ScalarConverter & operator=(ScalarConverter const & rhs) = delete; // Canonical

		static bool isChar(const std::string &str);
		static bool isInteger(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isSpecialFloat(const std::string& str);
		static void errorAllImpossible(void);
		static void convertSpecialFloat(std::string str);
		static void convertInteger(std::string str);
		static void convertChar(std::string str);
		static void convertFloat(std::string str);
		static void convertDouble(std::string str);
		static int calculatePrecision(std::string str);
};