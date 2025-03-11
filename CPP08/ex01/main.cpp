# include "Span.hpp"

int main()
{
	Span sp = Span(5);
	const std::string line = "-------------------------";

	//-----------------------testing the span exception---------------------//
	std::cout << line << "testing the span exception" << line  << std::endl << std::endl;
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (Span::NotEnoughNumbers &fl) {
		std::cout << fl.what() << std::endl;
	}

	//----------------------------adding the numbers-----------------------//
	std::cout << std::endl << line << "adding the numbers" << line << std::endl << std::endl;
	
	std::vector<int> test_values = {6, 3, 17, 9, 11, -5};

	for (int val : test_values) {
		try {
			sp.addNumber(val);
		}
		catch (Span::ListIfFull &fl) {
			std::cout << fl.what() << std::endl;
		}
	}

	//----------------finding shortest and longest spans-----------------//
	std::cout << std::endl << line << "finding shortest and longest spans" \
		<< line << std::endl << std::endl;
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (Span::NotEnoughNumbers &fl) {
		std::cout << fl.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::NotEnoughNumbers &fl) {
		std::cout << fl.what() << std::endl;
	}

	//----------------------------creating the range-----------------------//
	std::cout << std::endl << line << "creating the range" << line << std::endl << std::endl;
	Span sp2 = Span(10000);

	try {
		sp2.addRange(10000);
	}
	catch (Span::ListIfFull &fl) {
		std::cout << fl.what() << std::endl;
	}

	//----------------finding shortest and longest spans-----------------//
	std::cout << std::endl << line << "finding shortest and longest spans" \
		<< line << std::endl << std::endl;
	try {
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (Span::NotEnoughNumbers &fl) {
		std::cout << fl.what() << std::endl;
	}
	try {
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (Span::NotEnoughNumbers &fl) {
		std::cout << fl.what() << std::endl;
	}

	//-----------------------testing the span exception---------------------//
	std::cout << std::endl << line << "testing the span exception" << line  << std::endl << std::endl;
	try {
		sp2.addRange(5);
	}
	catch (Span::ListIfFull &fl) {
		std::cout << fl.what() << std::endl;
	}

	return 0;
}

/* int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
} */