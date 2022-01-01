/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:08:27 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/28 17:31:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed(void) : rawBits(0)
{
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const n) : rawBits(n * (1 << fractionalBits))
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : rawBits(roundf(n * (1 << fractionalBits)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &obj)
{
	//std::cout << "Copy constructor called\n";
	rawBits = obj.getRawBits();
}

// METHODS
Fixed::~Fixed(void)
{
	//std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n";
	return (rawBits);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (float)(rawBits) / (float)(1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return (rawBits >> fractionalBits);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

// OPERATOR OVERLOADS
// // Redirection operator
std::ostream &operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return (output);
}

// // Assignation operator
Fixed &Fixed::operator=(Fixed const &rhs)
{
	//std::cout << "Assignation operator called" << std::endl;
	this->rawBits = rhs.getRawBits();
	return *this;
}

// // Increments, decrements
Fixed Fixed::operator++(void)
{
	this->rawBits++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed copy = *this;
	this->rawBits++;
	return (copy);
}
Fixed Fixed::operator--(void)
{
	rawBits--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed copy = *this;
	this->rawBits--;
	return (copy);
}

// // Comparison operators
bool Fixed::operator > (Fixed const &rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator < (Fixed const &rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator >= (Fixed const &rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator <= (Fixed const &rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator == (Fixed const &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator != (Fixed const &rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

// // Arithmetic operators
Fixed Fixed::operator * (Fixed const &rhs)
{
	Fixed lhs = *this;
	lhs.setRawBits((lhs.getRawBits() * rhs.getRawBits()) / (1 << fractionalBits));
	return (lhs);
}
Fixed Fixed::operator + (Fixed const &rhs)
{
	Fixed lhs = *this;
	lhs.setRawBits(lhs.getRawBits() + rhs.getRawBits());
	return (lhs);
}
Fixed Fixed::operator - (Fixed const &rhs)
{
	Fixed lhs = *this;
	lhs.setRawBits(lhs.getRawBits() - rhs.getRawBits());
	return (lhs);
}
Fixed Fixed::operator / (Fixed const &rhs)
{
	Fixed lhs = *this;
	lhs.setRawBits(lhs.getRawBits() * (1 << fractionalBits) / rhs.getRawBits());
	return (lhs);
}

// Function definitions
Fixed &min(Fixed &lhs, Fixed &rhs)
{
	return (Fixed::min(lhs, rhs));
}
Fixed &max(Fixed &lhs, Fixed &rhs)
{
	return (Fixed::max(lhs, rhs));
}
Fixed const &min(Fixed const &lhs, Fixed const &rhs)
{
	return (Fixed::min(lhs, rhs));
}
Fixed const &max(Fixed const &lhs, Fixed const &rhs)
{
	return (Fixed::max(lhs, rhs));
}
