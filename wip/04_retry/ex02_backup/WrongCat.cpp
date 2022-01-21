/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:42:44 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat  (void) : WrongAnimal()
{
	std::cout << "[WrongCat] Default constructor called\n";
	WrongAnimal::type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &obj) : WrongAnimal()
{
	std::cout << "[WrongCat] Copy constructor called\n";
	if (this == &obj)
		return ;
	this->type = obj.type;
}

WrongCat &WrongCat::operator = (WrongCat const &obj)
{
	std::cout << "[WrongCat] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong cat noises\n";
}

WrongCat::~WrongCat (void) { std::cout << "[WrongCat] Destructor Called\n"; }
