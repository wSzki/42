/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:03:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/21 14:10:56 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void error(int err_no)
{
	std::cerr << RED << "Error" << RESET << "\n";
	if (err_no == ERR_ARG)
		std::cerr << "Invalid argument(s)\n";
	std::exit(1);
}

void	replace(std::ifstream &file, std::string filename, std::string target, std::string replacement)
{
	std::ofstream result_file(filename + ".replace");
	std::string   line;
	std::size_t   target_index;
	std::size_t   i;

	while (std::getline(file, line))
	{
		i = 0;
		target_index = line.find(target);
		if (target_index != std::string::npos)
		{
			while (i < target_index)
				result_file << line[i++];
			result_file << replacement;
			i += target.size();
			while (line[i])
				result_file << line[i++];
			result_file << std::endl;

		}
		else
			result_file << line << std::endl;
	}
	result_file.close();
}

int main(int ac, char **av)
{
	std::ifstream file;

	if (ac != 4)
		error(ERR_ARG);
	if (*av[2] == '\0' || *av[3] == '\0')
		error(ERR_ARG);
	file.open(av[1]);
	if (file.good() == false)
		error(ERR_ARG);
	if (file.is_open())
		replace(file,av[1], av[2], av[3]);
	file.close();
	return (0);
}
