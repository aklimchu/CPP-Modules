#include "ScalarConverter.hpp"

//-------------------------------Member functions------------------------------//


void ScalarConverter::convert(const std::string str) {
    // Create an array of member function pointers
	bool (*checkers[])(const std::string&) = {&ScalarConverter::isSpecialFloat, &ScalarConverter::isInteger, \
		&ScalarConverter::isChar, &ScalarConverter::isFloat, &ScalarConverter::isDouble};

	size_t i  = 0;
	int res_int = 0;
	char res_char = '\0';
	float res_float = 0;
	double res_double = 0;
	bool type_captured = false;

	for (i = 0; i < 4; i++) {
		if (checkers[i](str)) {
			type_captured = true;
			break;
		}
	}

	if (type_captured == false)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}

	switch (i)  {
		case 0:
			std::cout << "It's special float" << std::endl;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			res_float = std::stof(str);
			std::cout << "float: " << std::fixed << std::setprecision(1) << res_float << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(res_float) << std::endl << std::endl;				
			break;
		case 1:
			std::cout << "It's integer" << std::endl;
			try {
				res_int = std::stoi(str);
			}
			catch (const std::exception& e) {
				std::cout << "int: " << "impossible" << std::endl;
			}
			if (res_int < std::numeric_limits<char>::min() || res_int > std::numeric_limits<char>::max())
				std::cout << "char: impossible" << std::endl;
			else {
				std::cout << "char: " << static_cast<char>(res_int) << std::endl;
			}
			std::cout << "int: " << res_int << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(res_int) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(res_int) << std::endl << std::endl;
			break;
		case 2:
			std::cout << "It's char" << std::endl;
			res_char = str[0];
			res_int = static_cast<int>(res_char);
			res_float = static_cast<float>(res_char);
			res_double = static_cast<double>(res_char);
			break;
		case 3:
			try {
				res_float = std::stof(str);
			}
			catch (const std::exception& e) {
				std::cout << "float: " << "impossible" << std::endl;
			}
			if (res_float < std::numeric_limits<char>::min() || res_float > std::numeric_limits<char>::max())
				std::cout << "char: impossible" << std::endl;
			else {
				std::cout << "char: " << static_cast<char>(res_float) << std::endl;
			}
			res_double = static_cast<double>(res_float);
			if (res_double < std::numeric_limits<int>::min() || res_double > std::numeric_limits<int>::max())
				std::cout << "int: impossible" << std::endl;
			else {
				std::cout << "int: " << static_cast<int>(res_float) << std::endl;
			}
			std::cout << "float: " << std::fixed << std::setprecision(1) << res_float << "f" << std::endl;
			if (res_float < std::numeric_limits<double>::min() || res_float > std::numeric_limits<double>::max())
				std::cout << "double: impossible" << std::endl;
			else {
				std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(res_float) << std::endl << std::endl;				
			}
			break;
		case 4:
			std::cout << "It's double" << std::endl;
			/* res_double = std::stod(str);
			res_int = static_cast<int>(res_double);
			res_char = static_cast<char>(res_double);
			res_float = static_cast<float>(res_double);
			break; */
			try {
				res_double = std::stod(str);
			}
			catch (const std::exception& e) {
				std::cout << "double: " << "impossible" << std::endl;
			}
			if (res_double < std::numeric_limits<char>::min() || res_double > std::numeric_limits<char>::max())
				std::cout << "char: impossible" << std::endl;
			else {
				std::cout << "char: " << static_cast<char>(res_double) << std::endl;
			}
			if (res_double < std::numeric_limits<int>::min() || res_double > std::numeric_limits<int>::max())
				std::cout << "int: impossible" << std::endl;
			else {
				std::cout << "int: " << static_cast<int>(res_double) << std::endl;
			}
			std::cout << "double: " << std::fixed << std::setprecision(1) << res_double << std::endl << std::endl;				
			if (res_double < std::numeric_limits<float>::min() || res_double > std::numeric_limits<float>::max())
				std::cout << "float: impossible" << std::endl;
			else {
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(res_double) << "f" << std::endl << std::endl;				
			}
			break;
	}

	/* if (!std::isprint(res_char))
		std::cout << "char: " << "Non displayable" << std::endl;
	else {
		try {
			std::cout << "char: '" << res_char << "'" << std::endl;
		}
		catch (const std::exception & e) {
			std::cout << "char: " << "impossible" << std::endl;
		}
	}
	try {
		std::cout << "int: " << res_int << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << "int: " << "impossible" << std::endl;
	}
	try {
		std::cout << "float: " << std::fixed << std::setprecision(1) << res_float << "f" << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << "float: " << "impossible" << std::endl;
	}
	try {
		std::cout << "double: " << std::fixed << std::setprecision(1) << res_double << std::endl << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << "double: " << "impossible" << std::endl << std::endl;
	} */
}

bool ScalarConverter::isInteger(const std::string &str) {
    std::regex intRegex(R"(^[+-]?\d+$)");
	if (std::regex_match(str, intRegex)) {
		double check = std::stod(str);
		if (check < std::numeric_limits<int>::min() || check > std::numeric_limits<int>::max())
			return false;
		else
			return true;
	}
    return false;
}

bool ScalarConverter::isFloat(const std::string &str) {
	std::regex floatRegex(R"(^[+-]?(inff?|nan)$|^[+-]?\d*\.\d+([eE][+-]?\d+)?[fF]?$)");
    return std::regex_match(str, floatRegex);
}

bool ScalarConverter::isDouble(const std::string &str) {
	std::regex doubleRegex(R"(^[+-]?(inf|nan)$|^[+-]?\d+(\.\d+([eE][+-]?\d+)?)?$)");
    return std::regex_match(str, doubleRegex);
}

bool ScalarConverter::isChar(const std::string &str) {
    return str.size() == 1;
}

bool ScalarConverter::isSpecialFloat(const std::string& str) {
        return str == "inf" || str == "+inf" || str == "-inf" || str == "nan" ||
               str == "+inff" || str == "-inff" || str == "inff" || str == "nanf";
}
