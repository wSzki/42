/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:09:39 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/16 23:22:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./phonebook.hpp"

static void error(int errcode)
{
	std::cerr << "Error\n";
	if (errcode == ARG_NUM)
		std::cerr << "No arguments taken\n";
	if (errcode == INVALID_CMD)
		std::cerr << "Invalid command (ADD - SEARCH - EXIT)\n";
	exit (1);
}

int main(int ac, char **av)
{
	(void)av;
	int i;
	std::string str;
	Phonebook p;
	Contact *c;

	c = p.getContactList();
	i = -1;
	if (ac != 1)
		error(ARG_NUM);
	std::cout << "Enter a command - ADD - SEARCH - EXIT > ";
	while (std::getline(std::cin, str))
	{
		if (str == "EXIT")
			return (0);
		else if (str == "ADD")
			add(c, &i);
		else if (str == "SEARCH")
			search(c, i);
		std::cout << "Enter a command - ADD - SEARCH - EXIT > ";
	}
	return (0);
}
