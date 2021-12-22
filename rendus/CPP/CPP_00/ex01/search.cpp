/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:08:42 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/16 23:34:30 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void	print_header(void)
{
	std::cout << std::setw(10) << "index"      << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name"  << "|";
	std::cout << std::setw(10) << "nickname"   << std::endl;
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

static void print_all_contacts(Contact *c, int i)
{
	std::string buffer;

	for (int j = 0; j <= i; j++)
	{
		while (buffer.size() < 9)
			buffer.insert(0, 1, ' ');
		std::cout << buffer;
		std::cout << j << "|";
		format_and_print(c[j].getFirstName());
		std::cout << "|";
		format_and_print(c[j].getLastName());
		std::cout << "|";
		format_and_print(c[j].getNickName());
		std::cout << buffer << std::endl;
	}

}

static void print_contact(Contact c)
{
	std::cout << std::setw(16) << "First name: ";
	std::cout << c.getFirstName() << std::endl;
	std::cout << std::setw(16) << "Last name: ";
	std::cout << c.getLastName() << std::endl;
	std::cout << std::setw(16) << "Nickname: ";
	std::cout << c.getNickName() << std::endl;
	std::cout << std::setw(16) << "Phone number: ";
	std::cout << c.getPhoneNumber() << std::endl;
	std::cout << std::setw(16) << "Darkest secret: ";
	std::cout << c.getSecret() << std::endl;
}

void search(Contact *c, int i)
{
	int j;
	std::string buffer;

	j = -1;
	print_header();
	print_all_contacts(c, i);
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
		print_contact(c[i]);
	else
		std::cerr << "Contact does not exist" << std::endl;
}

