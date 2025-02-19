#include "ScalarConverter.hpp"

//-------------------------------Member functions------------------------------//

void ScalarConverter::convert(const std::string str) {
	bool (*checkers[])(const std::string&) = {&ScalarConverter::isSpecialFloat, &ScalarConverter::isInteger, \
		&ScalarConverter::isChar, &ScalarConverter::isDouble, &ScalarConverter::isFloat};
	int i;

	for (i = 0; i < 5; i++) {
		if (checkers[i](str)) {
			break;
		}
	}
	if (i == 5)
	{
		error_all_impossible();
		return;
	}
	switch (i)  {
		case 0:
			convert_special_float(str);
			break;
		case 1:
			convert_integer(str);
			break;
		case 2:
			convert_char(str);
			break;
		case 3:
			convert_double(str);
			break;
		case 4:
			convert_float(str);
			break;
	}
}

bool ScalarConverter::isInteger(const std::string &str) {
    std::regex intRegex(R"(^[+-]?\d+$)");
    return std::regex_match(str, intRegex);
}

bool ScalarConverter::isFloat(const std::string &str) {
	std::regex floatRegex(R"(^[+-]?(inff?|nan)$|^[+-]?\d*\.\d+([eE][+-]?\d+)?[fF]?$)");
    return std::regex_match(str, floatRegex);
}

bool ScalarConverter::isDouble(const std::string &str) {
	std::regex doubleRegex(R"(^[+-]?(inf|nan)$|^[+-]?\d*\.\d+([eE][+-]?\d+)?$)");
    return std::regex_match(str, doubleRegex);
}

bool ScalarConverter::isChar(const std::string &str) {
    return str.size() == 1;
}

bool ScalarConverter::isSpecialFloat(const std::string& str) {
        return str == "inf" || str == "+inf" || str == "-inf" || str == "nan" ||
               str == "+inff" || str == "-inff" || str == "inff" || str == "nanf";
}

void ScalarConverter::error_all_impossible(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert_special_float(std::string str)  {
	float res_float;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	res_float = std::stof(str);
	std::cout << "float: " << std::fixed << std::setprecision(1) << res_float << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(res_float) << std::endl;
}

void ScalarConverter::convert_integer(std::string str) {
	int res_int;

	try {
		res_int = std::stoi(str);
	}
	catch (const std::exception& e) {
		error_all_impossible();
		return;
	}
	if (res_int < std::numeric_limits<char>::min() || res_int > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(res_int)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else {
		std::cout << "char: '" << static_cast<char>(res_int) << "'" << std::endl;
	}
	std::cout << "int: " << res_int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(res_int) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(res_int) << std::endl;
}

void ScalarConverter::convert_char(std::string str) {
	char res_char;
	
	res_char = str[0];
	std::cout << "char: '" << res_char << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(res_char) << std::endl;
	std::cout << "float: " << static_cast<float>(res_char) << std::endl;
	std::cout << "double: " << static_cast<double>(res_char) << std::endl;
}

void ScalarConverter::convert_float(std::string str) {
	float res_float;
	double res_double;
	
	try {
		res_float = std::stof(str);
	}
	catch (const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (res_float < std::numeric_limits<char>::min() || res_float > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(res_float)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else {
		std::cout << "char: '" << static_cast<char>(res_float) << "'" << std::endl;
	}
	res_double = static_cast<double>(res_float);
	if (res_double < std::numeric_limits<int>::min() || res_double > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else {
		std::cout << "int: " << static_cast<int>(res_float) << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << res_float << "f" << std::endl;
	if (res_float < std::numeric_limits<double>::lowest() || res_float > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(res_float) << std::endl;				
	}
}

void ScalarConverter::convert_double(std::string str) {
	double res_double;
	
	try {
		res_double = std::stod(str);
	}
	catch (const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (res_double < std::numeric_limits<char>::min() || res_double > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(res_double)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else {
		std::cout << "char: '" << static_cast<char>(res_double) << "'" << std::endl;
	}
	if (res_double < std::numeric_limits<int>::min() || res_double > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else {
		std::cout << "int: " << static_cast<int>(res_double) << std::endl;
	}
	if (res_double < std::numeric_limits<float>::lowest() || res_double > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(res_double) << "f" << std::endl;				
	}
	std::cout << "double: " << std::fixed << std::setprecision(1) << res_double << std::endl;				
}