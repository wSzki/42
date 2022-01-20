/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:52:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:07:07 by wsz              ###   ########.fr       */
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
	if (this == &obj)
		return ;
	std::cout << "[WrongCat] Copy constructor called\n";
	this->type = obj.type;
}

WrongCat &WrongCat::operator = (WrongCat const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "[WrongCat] Assignation operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong cat noises\n";
}

WrongCat::~WrongCat (void) { std::cout << "[WrongCat] Destructor Called\n"; }
