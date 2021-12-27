/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:08:27 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/23 17:24:10 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called\n";
	rawBits = obj.getRawBits();
}

Fixed &Fixed::operator=(Fixed const &objectToCopy)
{
	std::cout << "Assignation operator called" << std::endl;
	this->rawBits = objectToCopy.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (rawBits);

}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	rawBits = raw;
}
