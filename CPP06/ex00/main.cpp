#include "ScalarConverter.hpp"

// change input handling to argc argv

int main(void) {
	ScalarConverter::convert("0");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("42.0f");
	std::cout << std::endl << std::endl << std::endl;

	ScalarConverter::convert("1233333333333333");
	std::cout << std::endl;
	ScalarConverter::convert("1233333333333333.333333333333333333333333333");
	std::cout << std::endl;
	ScalarConverter::convert("123");
	std::cout << std::endl;
	ScalarConverter::convert("-123");
	std::cout << std::endl;
	ScalarConverter::convert("1.23");
	std::cout << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("ab");
	std::cout << std::endl;
	ScalarConverter::convert("-4.2f");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("");
	std::cout << std::endl;
	ScalarConverter::convert("-");
}