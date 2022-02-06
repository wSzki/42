/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:41:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/06 02:18:22 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"
#include "colors.hpp"

void	err(std::string msg)
{
	std::cout
		<< RED << "[ERROR]"
		<< _R  << " : "
		<< msg << std::endl;
	exit(1);
}

static bool isValidValue(char *char_ptr) // https://stackoverflow.com/questions/447206/c-isfloat-function
{
	if (char_ptr == NULL)    return (false);
	if (char_ptr[0] == '\0') return (true);
	if (char_ptr[0] != 'f')
		if (isspace(char_ptr[0]) == false)
			return (false);
	for (int i = 1; char_ptr[i] != '\0'; i++)
		if (isspace(char_ptr[i]) == false)
			return (false);
	return (true);
}

static double av_to_double(char *str)
{
	char   *end_char = NULL;
	double data      = std::strtod(str, &end_char);
	std::string s    = str;

	if (s.length() == 1)
		if (isdigit(str[0]) == false)
			return (static_cast<double>(str[0]));
	if (isValidValue(end_char) == false)
		err("Invalid input");
	return (data);
}

int main(int ac, char **av)
{
	if (ac != 2)
		err("Invalid number of arguments");
	convert(av_to_double(av[1]));

	return (0);
}
