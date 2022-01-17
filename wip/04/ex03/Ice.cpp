/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:17:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/14 16:44:25 by wszurkow         ###   ########.fr       */
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
	(void)obj;
	std::cout << GREEN << "[Ice] Copy constructor called\n";
}

Ice &Ice::operator = (Ice const &obj)
{
	(void)obj;
	std::cout << GREEN << "[Ice] Assignation operator called" << std::endl;
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
