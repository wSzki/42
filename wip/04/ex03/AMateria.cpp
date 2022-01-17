/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:12:07 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/14 16:49:06 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "AMateria.hpp"

// Default
AMateria::AMateria (void) : type("none")
{
	std::cout << GREEN << "[AMateria] Default constructor called\n";
}

// Copy
AMateria::AMateria(AMateria const &obj)
{
	std::cout << GREEN << "[AMateria] Copy constructor called\n";
	this->type = obj.type;
}

// OVERLOADS
AMateria &AMateria::operator = (AMateria const &obj)
{
	std::cout << GREEN << "[AMateria] Assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

// METHODS
// /////////////////////////////////////////
AMateria::AMateria  (std::string const &type) : type(type)
{
	std::cout << GREEN << "[AMateria] Assignation constructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (type);
}

// /////////////////////////////////////////

// DESTRUCTOR
AMateria::~AMateria (void)
{
	std::cout << RED <<"[AMateria] Destructor Called\n";
}
