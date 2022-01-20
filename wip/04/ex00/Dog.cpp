/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:50:39 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:02:27 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog  (void) : Animal()
{
	std::cout << "[Dog] Default constructor called\n";
	Animal::type = "Dog";
}


Dog::Dog(Dog const &obj) : Animal()
{
	if (this == &obj)
		return ;
	std::cout << "[Dog] Copy constructor called\n";
	*this = obj;
}

Dog &Dog::operator = (Dog const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "[Dog] Assignation operator called" << std::endl;
	this->type = obj.type; // TODO [...]
	return (*this);
}

void Dog::makeSound(void) const
{
std::cout << "Woof\n";
}

Dog::~Dog (void)
{
	std::cout << "[Dog] Destructor Called\n";
}
