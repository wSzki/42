/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:12:07 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 01:12:42 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default
AMateria::AMateria (void) : type("none")
{
	std::cout << "[AMateria] Default constructor called\n";
}

// Copy
AMateria::AMateria(AMateria const &obj)
{
	std::cout << "[AMateria] Copy constructor called\n";
	this->type = obj.type;
}

// OVERLOADS
AMateria &AMateria::operator = (AMateria const &obj)
{
	std::cout << "[AMateria] Assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

// METHODS
// /////////////////////////////////////////
AMateria::AMateria  (std::string const &type) : type(type)
{
	std::cout << "[AMateria] Assignation constructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (type);
}
// /////////////////////////////////////////

// DESTRUCTOR
AMateria::~AMateria (void)
{
	std::cout << "[AMateria] Destructor Called\n";
}
