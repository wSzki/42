/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:17:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:38:45 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure  (void) : AMateria("cure")
{
	std::cout << GREEN << "[Cure] Default constructor called\n";
}

Cure::Cure(Cure const &obj) : AMateria(obj)
{
	std::cout << GREEN << "[Cure] Copy constructor called\n";
	if (this == &obj)
		return ;
}

Cure &Cure::operator = (Cure const &obj)
{
	std::cout << GREEN << "[Cure] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	(void)obj;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


Cure::~Cure (void) { std::cout << RED << "[Cure] Destructor Called\n"; }
