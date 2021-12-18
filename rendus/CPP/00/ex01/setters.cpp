/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:30:44 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/16 23:29:40 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::setFirstName(str s)
{
	first_name = s;
}

void Contact::setLastName(str s)
{
	last_name = s;
}

void Contact::setNickName(str s)
{
	nickname = s;
}

void Contact::setPhoneNumber(str s)
{
	phone_number = s;
}

void Contact::setSecret(str s)
{
	darkest_secret = s;
}

