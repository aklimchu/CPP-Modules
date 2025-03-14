#pragma once

#include <iostream>
#include <fstream>
#include <deque>
#include <limits>
#include <iomanip> // for std::fixed and std::setprecision
#include <string> // for to_string

class BitcoinExchange {
	public:
		BitcoinExchange(void) = delete; // Canonical
		BitcoinExchange(BitcoinExchange const & src) = delete; // Canonical
		~BitcoinExchange(void) = delete; // Canonical

		BitcoinExchange & operator=(BitcoinExchange const & rhs) = delete; // Canonical

		static void find_btc_price(std::string infile);
		static void closeStreams();

		class DatabaseAccess : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: can't access database");
				}
		};

		class InfileAccess : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: can't access incoming file");
				}
		};

		class EmptyInfile : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: incoming file is empty");
				}
		};

		class EmptyDatabase : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: database is empty");
				}
		};

		class EmptyLine : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: line is empty");
				}
		};

		class NotPositive : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: not a positive number");
				}
		};

		class TooLarge : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: too large a number");
				}
		};

		class BadInput : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: bad input");
				}
		};

		class NoEarlierDate : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: no earlier date found");
				}
		};

	private:
		static std::ifstream input_stream;
		static std::ifstream database_stream;
		static std::deque <std::string> line_divided;
		static std::deque <std::string> date_divided;

		static void check_infiles(std::string infile);
		static void analyze_line(std::string line);
		static std::deque<std::string> ft_split(std::string & line, const char & sep);
		static void check_date(std::string str);
		static void check_amount(std::string str);
		static void modify_line(void);
		static std::string find_previous_line(void);
		static int calculatePrecision(double num);
		static int all_next_zeros(std::string str, int start);
};