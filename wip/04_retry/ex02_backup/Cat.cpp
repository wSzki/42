/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:42:14 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat  (void) : Animal(), brain(NULL)
{
	std::cout << "[Cat] Default constructor called\n";
	Animal::type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat const &obj) : Animal(), brain(NULL)
{
	std::cout << "[Cat] Copy constructor called\n";
	if (this == &obj)
		return ;
	this->type = obj.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*obj.brain);
}

Cat &Cat::operator = (Cat const &obj)
{
	std::cout << "[Cat] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow\n";
}

Cat::~Cat (void)
{
	std::cout << "[Cat] Destructor Called\n";
	delete brain;
}

Brain &Cat::getBrain(void) const
{
	return (*brain);
}

