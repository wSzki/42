/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:38:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/16 23:28:29 by wszurkow         ###   ########.fr       */
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

typedef std::string str;

class Contact{
	public:
		void setFirstName(str s);
		void setLastName(str s);
		void setNickName(str s);
		void setPhoneNumber(str s);
		void setSecret(str s);

		str getFirstName(void);
		str getLastName(void);
		str getNickName(void);
		str getPhoneNumber(void);
		str getSecret(void);

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class Phonebook{
	public:
		Contact *getContactList(void);
	private:
		Contact contact_list[8];
};

void search(Contact *c, int i);
void add(Contact *c, int *i);

#endif
