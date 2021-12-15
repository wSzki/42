/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:09:39 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/14 16:01:54 by wszurkow         ###   ########.fr       */
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

	std::cout << std::setw(10) << "index"      << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name"  << "|";
	std::cout << std::setw(10) << "nickname"   << std::endl;

	while (j <= i)
	{
		while (buffer.size() < 9)
			buffer.insert(0, 1, ' ');
		std::cout << buffer;
		std::cout << j << "|";
		format_and_print(p.contact_list[j].first_name);
		std::cout << "|";
		format_and_print(p.contact_list[j].last_name);
		std::cout << "|";
		format_and_print(p.contact_list[j].nickname);
		std::cout << buffer << std::endl;
		j++;
	}
	std::cout << "Input index number > " ;
	std::getline(std::cin, buffer);
	if (buffer.length() == 1 && std::isdigit(buffer[0]))
	{
	try {
		j = std::stoi(buffer);
	}
	catch (const std::invalid_argument) {
		std::cerr << "Invalid input" << '\n';
		return ;
	}
	}
	if (j <= i && j >= 0)
		print_contact(p, j);
	else
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
	std::cout << "Enter a command - ADD - SEARCH - EXIT > ";
	while (std::getline(std::cin, str))
	{
		if (str == "EXIT")
			return (0);
		else if (str == "ADD")
			p = add(p, &i);
		else if (str == "SEARCH")
			search(p, i);
		std::cout << "Enter a command - ADD - SEARCH - EXIT > ";
	}
	return (0);
}
