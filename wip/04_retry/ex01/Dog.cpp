/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:50:39 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/21 16:42:07 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog  (void) :
	Animal(),
	brain(new Brain())
{
	std::cout << "[Dog] Default constructor called\n";
	Animal::type = "Dog";
}

Dog::Dog(Dog const &obj) :
	Animal()
{
	std::cout << "[Dog] Copy constructor called\n";
	if (this == &obj)
		return ;
	this->brain = NULL;
	*this = obj;
}

Dog &Dog::operator = (Dog const &obj)
{
	std::cout << "[Dog] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof\n";
}

Dog::~Dog (void)
{
	std::cout << "[Dog] Destructor Called\n";
	delete brain;
}

Brain &Dog::getBrain(void) const
{
	return (*brain);
}
