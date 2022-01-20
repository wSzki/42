/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:50:39 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:27:12 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog  (void) : Animal(), brain(NULL)
{
	std::cout << "[Dog] Default constructor called\n";
	Animal::type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog const &obj) : Animal(), brain(NULL)
{
	if (this == &obj)
		return ;
	std::cout << "[Dog] Copy constructor called\n";
	this->type = obj.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*obj.brain);
}

Dog &Dog::operator = (Dog const &obj)
{
	this->brain = NULL;
	if (this == &obj)
		return (*this);
	std::cout << "[Dog] Assignation operator called" << std::endl;
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
