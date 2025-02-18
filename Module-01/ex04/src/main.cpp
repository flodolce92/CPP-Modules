/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:09 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/20 03:11:19 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

bool openFiles(std::ifstream &infile, std::ofstream &outfile, const char *filename)
{
	// Open input file
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cout << "Error opening input file: " << filename << std::endl;
		return (false);
	}

	// Open output file
	std::string outputFileName = std::string(filename) + ".replace";
	outfile.open(outputFileName.c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
	{
		std::cout << "Error opening output file: " << outputFileName << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of argument" << std::endl;
		std::cout << "Usage: ./replace <filename> <find> <replace>" << std::endl;
		return (1);
	}

	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;
	std::string		find = argv[2];
	std::string		replace = argv[3];

	// Check if find string is empty
	if (find.empty())
	{
		std::cout << "Find string is empty" << std::endl;
		return (1);
	}

	// Open files
	if (!openFiles(infile, outfile, argv[1]))
		return (1);

	// Read file line by line
	while (std::getline(infile, line))
	{
		std::size_t	found = line.find(argv[2]);
		while (found != std::string::npos)
		{
			line.erase(found, find.length());
			line.insert(found, replace);
			found = line.find(argv[2]);
		}
		outfile << line << std::endl;
	}

	infile.close();
	outfile.close();
	return (0);
}
