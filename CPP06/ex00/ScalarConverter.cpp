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
		errorAllImpossible();
		return;
	}
	switch (i)  {
		case 0:
			convertSpecialFloat(str);
			break;
		case 1:
			convertInteger(str);
			break;
		case 2:
			convertChar(str);
			break;
		case 3:
			convertDouble(str);
			break;
		case 4:
			convertFloat(str);
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
	std::regex doubleRegex(R"(^[+-]?(inf|nan)$|^[+-]?\d+(\.\d*)?([eE][+-]?\d+)?$)");
    return std::regex_match(str, doubleRegex);
}

bool ScalarConverter::isChar(const std::string &str) {
    return str.size() == 1;
}

bool ScalarConverter::isSpecialFloat(const std::string& str) {
        return str == "inf" || str == "+inf" || str == "-inf" || str == "nan" ||
               str == "+inff" || str == "-inff" || str == "inff" || str == "nanf";
}

void ScalarConverter::errorAllImpossible(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convertSpecialFloat(std::string str)  {
	float res_float;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	res_float = std::stof(str);
	std::cout << "float: " << std::fixed << std::setprecision(calculatePrecision(str)) \
		<< res_float << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(calculatePrecision(str)) \
		<< static_cast<double>(res_float) << std::endl;
}

void ScalarConverter::convertInteger(std::string str) {
	int res_int;

	try {
		res_int = std::stoi(str);
	}
	catch (const std::exception& e) {
		errorAllImpossible();
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
	std::cout << "float: " << std::fixed << std::setprecision(calculatePrecision(str)) \
		<< static_cast<float>(res_int) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(calculatePrecision(str)) \
		<< static_cast<double>(res_int) << std::endl;
}

void ScalarConverter::convertChar(std::string str) {
	char res_char;
	
	res_char = str[0];
	std::cout << "char: '" << res_char << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(res_char) << std::endl;
	std::cout << "float: " << static_cast<float>(res_char) << std::endl;
	std::cout << "double: " << static_cast<double>(res_char) << std::endl;
}

void ScalarConverter::convertFloat(std::string str) {
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
	std::cout << "float: " << std::fixed << std::setprecision(calculatePrecision(str)) \
		<< res_float << "f" << std::endl;
	if (res_float < std::numeric_limits<double>::lowest() || res_float > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else {
		std::cout << "double: " << std::fixed << std::setprecision(calculatePrecision(str)) \
			<< static_cast<double>(res_float) << std::endl;				
	}
}

void ScalarConverter::convertDouble(std::string str) {
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
		std::cout << "float: " << std::fixed << std::setprecision(calculatePrecision(str)) \
			<< static_cast<float>(res_double) << "f" << std::endl;				
	}
	std::cout << "double: " << std::fixed << std::setprecision(calculatePrecision(str)) \
		<< res_double << std::endl;				
}

int ScalarConverter::calculatePrecision(std::string str) {
	int i = 0;

	while (str[i] && str[i] != '.')
		i++;
	int count = 0;
	while (str[i] && str[i + 1] && str[i + 1] != 'f'  && str[i + 1] != 'F') {
		i++;
		count++;
	}
	if (count == 0)
		return 1;
	else
		return count;
}