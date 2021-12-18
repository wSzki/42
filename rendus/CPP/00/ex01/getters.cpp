/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:30:44 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/17 00:27:47 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

str Contact::getFirstName(void)
{
	return (first_name);
}

str Contact::getLastName(void)
{
	return (last_name);
}

str Contact::getNickName(void)
{
	return (nickname);
}

str Contact::getPhoneNumber(void)
{
	return (phone_number);
}

str Contact::getSecret(void)
{
	return (darkest_secret);
}

Contact *Phonebook::getContactList(void)
{
	return (contact_list);
}
