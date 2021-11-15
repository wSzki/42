/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:09:39 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/15 02:52:46 by wszurkow         ###   ########.fr       */
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

static Phonebook add(Phonebook p, int *i)
{
	if (*i >= 7)
		std::cerr << "CONTACT LIST FULL" << std::endl;
	else
	{
		*i += 1;
		std::cout << "First_name: ";
		std::getline(std::cin, p.contact_list[*i].first_name);
		std::cout << "Last_name: ";
		std::getline(std::cin, p.contact_list[*i].last_name);
		std::cout << "Nickname: ";
		std::getline(std::cin, p.contact_list[*i].nickname);
		std::cout << "Phone number: ";
		std::getline(std::cin, p.contact_list[*i].phone_number);
		std::cout << "Darkest secret: ";
		std::getline(std::cin, p.contact_list[*i].darkest_secret);
	}
	return (p);
}

static void format_and_print(std::string buffer)
{
	if (buffer.size() > 10)
	{
		buffer.resize(9);
		buffer.append(".");
	}
	std::cout << std::setw(10) << buffer;
}

static void print_contact(Phonebook p, int j)
{
	Contact c;

	c = p.contact_list[j];
	std::cout << std::setw(16) << "First name: ";
	std::cout << c.first_name << std::endl;
	std::cout << std::setw(16) << "Last name: ";
	std::cout << c.last_name << std::endl;
	std::cout << std::setw(16) << "Nickname: ";
	std::cout << c.nickname << std::endl;
	std::cout << std::setw(16) << "Phone number: ";
	std::cout << c.phone_number << std::endl;
	std::cout << std::setw(16) << "Darkest secret: ";
	std::cout << c.darkest_secret << std::endl;
}

static void search(Phonebook p, int i)
{
	int j;
	std::string buffer;

	j = 0;
	while (j <= i)
	{
		std::cout << j;
		while (buffer.size() < 10)
			buffer.insert(0, 1, ' ');
		std::cout << " | ";
		format_and_print(p.contact_list[j].first_name);
		std::cout << " | ";
		format_and_print(p.contact_list[j].last_name);
		std::cout << " | ";
		format_and_print(p.contact_list[j].nickname);
		std::cout << buffer << std::endl;
		j++;
	}
	std::getline(std::cin, buffer);
	try {
		j = std::stoi(buffer);
	}
	catch (const std::invalid_argument) {
		std::cerr << "Invalid argument" << '\n';
		return ;
	}
	if (j <= i && j >= 0)
		print_contact(p, j);
	else if (j < 8)
		std::cerr << "Contact does not exist" << std::endl;
}

int main(int ac, char **av)
{
	(void)av;
	int i;
	std::string str;
	Phonebook p;

	i = -1;
	if (ac != 1)
		error(ARG_NUM);
	while (std::getline(std::cin, str))
	{
		if (str == "EXIT")
			return (0);
		else if (str == "ADD")
			p = add(p, &i);
		else if (str == "SEARCH")
			search(p, i);
		else
			std::cerr << "Invalid input" << std::endl;
	}
	return (0);
}
