/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:50 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/06 15:21:39 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Unknown type")
{
	std::cout << "[Animal] Default constructor called\n";
}

Animal::Animal(Animal const &obj)
{
	std::cout << "[Animal] Copy constructor called\n";
	*this = obj;
}

Animal &Animal::operator = (Animal const &obj)
{
	std::cout << "[Animal] Assignation operator called" << std::endl;
	*this = obj;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "Unknown sound\n";
}

std::string Animal::getType (void) const 		{ return (type); }
void 		Animal::setType (std::string type)	{ this->type = type; }

Animal::~Animal (void)
{
	std::cout << "[Animal] Destructor Called\n";
}