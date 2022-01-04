/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/04 02:30:29 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat  (void) : Animal()
{
	std::cout << "[Cat] Default constructor called\n";
	Animal::type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat const &obj) : Animal()
{
	std::cout << "[Cat] Copy constructor called\n";
	brain = new Brain();
	this->brain = obj.brain;
	this->type = obj.type;
}

Cat &Cat::operator = (Cat const &obj)
{
	std::cout << "[Cat] Assignation operator called" << std::endl;
	this->type = obj.type;
	this->brain = obj.brain;
	return (*this);
}

std::string Cat::getIdea() const
{
	return (brain->ideas[0]);
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
