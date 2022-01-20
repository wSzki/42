/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:50 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:03:22 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Unknown type")
{
	std::cout << "[WrongAnimal] Default constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj)
{
	if (this == &obj)
		return ;
	std::cout << "[WrongAnimal] Copy constructor called\n";
	*this = obj;
}

WrongAnimal &WrongAnimal::operator = (WrongAnimal const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "[WrongAnimal] Assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
		std::cout << "Wrong animal noises\n";
}

std::string WrongAnimal::getType (void) const 		{ return (type); }
void 		WrongAnimal::setType (std::string type)	{ this->type = type; }

WrongAnimal::~WrongAnimal (void)
{
	std::cout << "[WrongAnimal] Destructor Called\n";
}
