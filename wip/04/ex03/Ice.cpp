/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:17:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 00:56:41 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice  (void) : AMateria("ice")
{
	std::cout << "[Ice] Default constructor called\n";
}

Ice::Ice(Ice const &obj) : AMateria(obj)
{
	(void)obj;
	std::cout << "[Ice] Copy constructor called\n";
}

Ice &Ice::operator = (Ice const &obj)
{
	(void)obj;
	std::cout << "[Ice] Assignation operator called" << std::endl;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

Ice::~Ice (void) { std::cout << "[Ice] Destructor Called\n"; }
