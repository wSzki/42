/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:41:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/31 23:38:41 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cerrno>
#include <cstdlib>
#include <string>
#include <sstream>

void	err(std::string msg)
{
	std::cout
		<< RED << "[ERROR]"
		<< _R  << " : "
		<< msg << std::endl;
	exit(1);
}

bool isNum( std::string str) // https://stackoverflow.com/questions/447206/c-isfloat-function
{
	std::istringstream iss(str);
	float f;
	iss >> std::noskipws >> f;       // noskipws considers leading whitespace invalid
	return iss.eof() && !iss.fail(); // Check the entire string was consumed and if either failbit or badbit is set
}

int main(int ac, char **av)
{

	char*  end       = NULL;
	size_t av_len    = std::strlen(av[1]);
	char   last_char = av[1][av_len - 1];

	if (ac != 2)
		err("Invalid number of arguments");
	if (last_char == 'f')
		av[1] = strndup(av[1], av_len - 1);
	if (isNum(av[1]) == false)
		err("Not a valid number or character");


	char *s = &(av[1][av_len]);

	double f = std::strtod(av[1], &end);
	std::cout << &end << std::endl;
	std::cout << &s << std::endl;
	std::cout << "############" << std::endl;
	(void)f;


	for (double f = std::strtod(av[1], &end); av[1] != end; f = std::strtod(av[1], &end))
	{
		std::cout << "'" << std::string(av[1], end - av[1]) << "' -> ";
		av[1] = end;
		if (errno == ERANGE){
			std::cout << "range error, got ";
			errno = 0;
		}
		std::cout << f << '\n';
	}

	return (0);
}
