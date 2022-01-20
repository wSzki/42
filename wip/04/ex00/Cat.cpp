/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:02:08 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat  (void) : Animal()
{
	std::cout << "[Cat] Default constructor called\n";
	Animal::type = "Cat";
}

Cat::Cat(Cat const &obj) : Animal()
{
	if (this == &obj)
		return ;
	std::cout << "[Cat] Copy constructor called\n";
	this->type = obj.type;
}

Cat &Cat::operator = (Cat const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "[Cat] Assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow\n";
}

Cat::~Cat (void) { std::cout << "[Cat] Destructor Called\n"; }
