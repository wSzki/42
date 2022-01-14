/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:17:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 20:54:17 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure  (void) : AMateria("cure")
{
	std::cout << GREEN << "[Cure] Default constructor called\n";
}

Cure::Cure(Cure const &obj) : AMateria(obj)
{
	(void)obj;
	std::cout << GREEN << "[Cure] Copy constructor called\n";
}

Cure &Cure::operator = (Cure const &obj)
{
	(void)obj;
	std::cout << GREEN << "[Cure] Assignation operator called" << std::endl;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

Cure::~Cure (void) { std::cout << RED << "[Cure] Destructor Called\n"; }
