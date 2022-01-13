/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:17:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 00:56:50 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure  (void) : AMateria("cure")
{
	std::cout << "[Cure] Default constructor called\n";
}

Cure::Cure(Cure const &obj) : AMateria(obj)
{
	(void)obj;
	std::cout << "[Cure] Copy constructor called\n";
}

Cure &Cure::operator = (Cure const &obj)
{
	(void)obj;
	std::cout << "[Cure] Assignation operator called" << std::endl;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

Cure::~Cure (void) { std::cout << "[Cure] Destructor Called\n"; }
