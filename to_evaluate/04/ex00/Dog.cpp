/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:50:39 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/21 17:04:13 by wsz              ###   ########.fr       */
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
	std::cout << "[Dog] Copy constructor called\n";
	if (this == &obj)
		return ;
	*this = obj;
}

Dog &Dog::operator = (Dog const &obj)
{
	std::cout << "[Dog] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
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
