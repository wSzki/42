/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:38:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/15 02:40:00 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>

#define ARG_NUM 1
#define INVALID_CMD 2

class Contact{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class Phonebook{
	public:
		Contact contact_list[8];
};

#endif
