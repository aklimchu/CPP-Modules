/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:35 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:36 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

int open_files(std::ifstream& input_stream, std::string infile_name, \
	std::ofstream& output_stream){
	input_stream.open(infile_name, std::ifstream::in);
	if (!input_stream){
		std::cerr << "Can't open input file" << std::endl;
		return (1);
	}
	std::string new_file = infile_name + ".replace";

	output_stream.open(new_file, std::ifstream::out);

	if (!output_stream){
		std::cerr << "Can't create output file" << std::endl;
		return (1);
	}
	return (0);
}

void replace_loop(std::string &new_line, std::string s1, std::string s2) {
		int pos_begin = 0;
		int pos_found;

		while (1) {
			if ((new_line.find(s1, pos_begin)) != std::string::npos) {
				pos_found = new_line.find(s1, pos_begin);
				new_line.erase(pos_found, s1.length());
				new_line.insert(pos_found, s2);
				pos_begin = pos_found + s2.length();
			}
			else
				break ;
		}
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Incorrect number of arguments" << std::endl;
		return 1;
	}
	
	std::ifstream input_stream;
	std::ofstream output_stream;

	if (open_files(input_stream, (std::string)argv[1], output_stream) == 1)
		return 1;

	std::string line;
	std::string new_line;
	while (getline(input_stream, line)) {
		new_line = line;
		replace_loop(new_line, std::string(argv[2]), std::string(argv[3]));
		output_stream << new_line << std::endl;
	}

	input_stream.close();
	output_stream.close();
}