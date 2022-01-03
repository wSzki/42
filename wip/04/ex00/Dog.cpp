/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:50:39 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/02 20:14:51 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog  (void) { std::cout << "[Dog] Default constructor called\n"; }
Dog::~Dog (void) { std::cout << "[Dog] Destructor Called\n"; }
Dog::Dog(Dog const &obj)
{
	std::cout << "[Dog] Copy constructor called\n";
	*this = obj;
}

Dog &Dog::operator = (Dog const &obj)
{
	std::cout << "[Dog] Assignation operator called" << std::endl;
	this->type = obj.type; // TODO [...]
	return (*this);
}

