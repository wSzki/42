/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:07:17 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/16 23:31:42 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void add(Contact *c, int *i)
{
	std::string buffer;

	if (*i >= 7)
		std::cerr << "CONTACT LIST FULL" << std::endl;
	else
	{
		*i += 1;
		std::cout << "First_name: ";
		std::getline(std::cin, buffer);
		c[*i].setFirstName(buffer);

		std::cout << "Last_name: ";
		std::getline(std::cin, buffer);
		c[*i].setLastName(buffer);

		std::cout << "Nickname: ";
		std::getline(std::cin, buffer);
		c[*i].setNickName(buffer);

		std::cout << "Phone number: ";
		std::getline(std::cin, buffer);
		c[*i].setPhoneNumber(buffer);

		std::cout << "Darkest secret: ";
		std::getline(std::cin, buffer);
		c[*i].setSecret(buffer);
	}
}
