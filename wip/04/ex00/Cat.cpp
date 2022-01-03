/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/03 15:26:40 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat  (void)
{
	std::cout << "[Cat] Default constructor called\n";
	Animal::type = "Cat";
}

Cat::~Cat (void) { std::cout << "[Cat] Destructor Called\n"; }

Cat::Cat(Cat const &obj)
{
	std::cout << "[Cat] Copy constructor called\n";
	*this = obj;
}

Cat &Cat::operator = (Cat const &obj)
{
	std::cout << "[Cat] Assignation operator called" << std::endl;
	*this = obj;
	return (*this);
}

