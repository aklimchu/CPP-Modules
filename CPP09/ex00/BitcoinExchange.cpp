#include "BitcoinExchange.hpp"

std::ifstream BitcoinExchange::input_stream;
std::ifstream BitcoinExchange::database_stream;
std::deque <std::string> BitcoinExchange::line_divided;
std::deque <std::string> BitcoinExchange::date_divided;

//-------------------------------Member functions------------------------------//

void BitcoinExchange::find_btc_price(std::string infile) {
	try {
		check_infiles(infile);
	}
	catch (std::exception & e) {
		throw;
	}

	std::string line;
	if (!getline(input_stream, line)) {
		throw EmptyInfile();
	}

	if (!getline(database_stream, line)) {
		throw EmptyDatabase();
	}
	
	while (getline(input_stream, line)) {
		try {
			analyze_line(line);
			modify_line();
		}
		catch (BitcoinExchange::BadInput & e) {
			std::cerr << e.what() << " => " << line << std::endl;
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::check_infiles(std::string infile) {
	
	database_stream.open("data.csv", std::ifstream::in);
	if (!database_stream)
		throw DatabaseAccess();

	input_stream.open(infile, std::ifstream::in);
	if (!input_stream)
		throw InfileAccess();
}

void BitcoinExchange::analyze_line(std::string line) {
	if (line.empty())
		throw EmptyLine();
	line_divided = ft_split(line, '|');
	if (line_divided.size() != 2)
		throw BadInput();
	try {
		check_date(line_divided[0]);
		check_amount(line_divided[1]);
	}
	catch (...) {
		throw;
	}
}

std::deque<std::string> BitcoinExchange::ft_split(std::string & line, const char & sep)
{
    std::deque<std::string> v;
    size_t start;
    size_t end = 0;

    while ((start = line.find_first_not_of(sep, end)) != std::string::npos)
    {
        end = line.find(sep, start);
        v.push_back(line.substr(start, end - start));
    }
    return v;
}

void BitcoinExchange::check_date(std::string str) {
		int year = 0;
		int month = 0;
		int day = 0;

	    date_divided = ft_split(str, '-');

		if (date_divided.size() != 3)
			throw BadInput();
		try {
			size_t pos;

			year = std::stoi(date_divided[0], &pos);
        	if (pos != date_divided[0].size())
            	throw BadInput();

			month = std::stoi(date_divided[1], &pos);
        	if (pos != date_divided[1].size())
            	throw BadInput();

			day = std::stoi(date_divided[2], &pos);
        	if (pos != date_divided[2].size() - 1 || date_divided[2].back() != ' ')
            	throw std::exception();
		}
		catch (...) {
			throw;
		}

		if (year < 2008 || year > 2025 || month < 1 || month > 12 \
			|| day < 1 || day > 31) {
			throw BadInput();
		}

		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			throw BadInput();
		
		if (((month == 2 && year % 4 == 0) && day > 29) || \
			(month == 2 && day > 28))
			throw BadInput();

}


void BitcoinExchange::check_amount(std::string str) {
	double amount = 0;

	try {
		size_t pos;
        amount = std::stof(str, &pos);

        if (pos != str.size())
			throw BadInput();
	}
	catch (...) {
		throw BadInput();
	}
	if (amount > std::numeric_limits<int>::max())
		throw TooLarge();

	if (amount < 0)
		throw NotPositive();

}

void BitcoinExchange::modify_line(void) {
	std::string database_line;
	bool line_found = false;
	double price = 0;
	double amount = 0;

	database_stream.clear();
	database_stream.seekg(0, std::ios::beg);

	while (getline(database_stream, database_line)) {
		if ((line_divided[0].substr(0, 10) == database_line.substr(0, 10))) {
			std::cout << line_divided[0] << "=>" << line_divided[1] << " = ";
			line_found = true;
			break;
		}
	}

	try {
		if (!line_found) {
			database_line = find_previous_line();
			std::cout << line_divided[0] << "=>" << line_divided[1] << " = ";
		}
		std::string price_str = database_line.substr(11, database_line.size() - 11);
		price = std::stod(price_str);
		amount = std::stod(line_divided[1]);
	}
	catch (...) {
		throw;
	}

	double result;
	try {
		result = price * amount;
	}
	catch (...) {
		throw TooLarge();
	}

	std::cout << std::fixed << std::setprecision(calculatePrecision(result)) << \
		result << std::endl;
}

std::string BitcoinExchange::find_previous_line(void) {
	std::string database_line;
	std::string previous_database_line = "9";
	
	database_stream.clear();
	database_stream.seekg(0, std::ios::beg);

	while (getline(database_stream, database_line)) {
		if (line_divided[0].compare(database_line) < 0 && \
			line_divided[0].compare(previous_database_line) > 0) {
			try {
				check_date(previous_database_line.substr(0, 10) + " ");
				return (previous_database_line);
			}
			catch (...) {
				throw NoEarlierDate();
			}
		}
		previous_database_line = database_line;
	}
	throw NoEarlierDate();
}

void BitcoinExchange::closeStreams() {
    if (input_stream.is_open()) {
        input_stream.close();
    }
    if (database_stream.is_open()) {
        database_stream.close();
    }
}

int BitcoinExchange::calculatePrecision(double num) {
	std::string str = std::to_string(num);
	
	int i = 0;

	while (str[i] && str[i] != '.')
		i++;
	if (str[i])
		i++;
	int count = 0;
	while (str[i] && str[i + 1] && str[i + 1] != 'f'  && str[i + 1] != 'F' && \
		!all_next_zeros(str, i)) {
		i++;
		count++;
	}
	return count;
}

int BitcoinExchange::all_next_zeros(std::string str, int start) {
	int i = start;
	
	while (str[i]) {
		if (str[i] != '0') {
			return 0;
		}
		i++;
	}
	return 1;
}
