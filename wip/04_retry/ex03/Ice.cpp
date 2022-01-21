/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:17:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:38:31 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice  (void) : AMateria("ice")
{
	std::cout << GREEN << "[Ice] Default constructor called\n";
}

Ice::Ice(Ice const &obj) : AMateria(obj)
{
	std::cout << GREEN << "[Ice] Copy constructor called\n";
	if (this == &obj)
		return ;
}

Ice &Ice::operator = (Ice const &obj)
{
	std::cout << GREEN << "[Ice] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


Ice::~Ice (void) { std::cout << RED << "[Ice] Destructor Called\n"; }
