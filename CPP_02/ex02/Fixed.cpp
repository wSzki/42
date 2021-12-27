/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:08:27 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/27 18:42:03 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	rawBits = n << fractionalBits;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = (n * (1 << fractionalBits));
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

float Fixed::toFloat(void) const
{
	return (float)(rawBits) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return ((rawBits >> fractionalBits));
}
std::ostream &operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return (output);
}
