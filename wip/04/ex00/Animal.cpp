/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:50 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/02 20:23:14 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal  (void) { std::cout << "[Animal] Default constructor called\n"; }
Animal::~Animal (void) { std::cout << "[Animal] Destructor Called\n"; }
Animal::Animal(Animal const &obj)
{
	std::cout << "[Animal] Copy constructor called\n";
	*this = obj;
}

Animal &Animal::operator = (Animal const &obj)
{
	std::cout << "[Animal] Assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}


std::string Animal::getType (void) const 		{ return (type); }
void 		Animal::setType (std::string type)	{ this->type = type; }

