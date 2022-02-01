/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:41:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/01 04:02:28 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"
#include "colors.hpp"
#include <exception>

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

void convert_char(double data)
{
	if(data >= 32 && data <= 126)
		std::cout << "char: '" << static_cast<char>(data) << "'" << std::endl;
	else if(data < 0 || data > 127 )//|| std::isnan(data))
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;


}

void convert(double data)
{

	convert_char   (data);
	//convert_int    (data);
	//convert_float  (data);
	//convert_double (data);


}

void convertNan_exit (void)
{

	std::cout << "char:   impossible" << std::endl;
	std::cout << "int:    impossible" << std::endl;
	std::cout << "float:  nanf" << std::endl;
	std::cout << "double: nan"  << std::endl;
	exit(0);
}

int main(int ac, char **av)
{

	size_t av_len    = std::strlen(av[1]);
	char   last_char = av[1][av_len - 1];

	if (ac != 2)
		err("Invalid number of arguments");
	if (last_char == 'f')
		av[1] = strndup(av[1], av_len - 1);
	if (isNum(av[1]) == false)
		convertNan_exit();
	double data = std::strtod(av[1], NULL); // second parameter supposed to be char ** end
	std::cout <<  data << std::endl;
	convert(data);
	return (0);
}
