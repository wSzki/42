/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/21 16:23:10 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat  (void) : Animal()
{
	std::cout << "[Cat] Default constructor called\n";
	Animal::type = "Cat";
	// Is equivalent to :
	//this->type = "Cat";
	//type = "Cat";
}

Cat::Cat(Cat const &obj) : Animal()
{
	std::cout << "[Cat] Copy constructor called\n";
	if (this == &obj)
		return ;
	this->type = obj.type;
}

Cat &Cat::operator = (Cat const &obj)
{
	std::cout << "[Cat] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow\n";
}

Cat::~Cat (void) { std::cout << "[Cat] Destructor Called\n"; }
