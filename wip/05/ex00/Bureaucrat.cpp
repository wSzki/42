/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:23:56 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/19 01:30:34 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <ostream>
#include <iomanip>

// Default
Bureaucrat::Bureaucrat (void) :
	name("Unknown"),
	grade(150)
{ std::cout << GREEN "[Bureaucrat] Default constructor called\n" << _R; }

Bureaucrat::Bureaucrat(std::string name, int grade) :
	name(name),
	grade(grade)
{ std::cout << GREEN "[Bureaucrat] Constructor called\n" << _R; }

// Copy
Bureaucrat::Bureaucrat(Bureaucrat const &obj) :
	name(obj.name),
	grade(obj.grade)
{ std::cout << GREEN "[Bureaucrat] Copy constructor called\n" << _R; }

// OVERLOADS
Bureaucrat &Bureaucrat::operator = (Bureaucrat const &obj)
{
	std::cout << GREEN "[Bureaucrat] Assignation operator called" << _R << std::endl;
	*this = Bureaucrat(obj.name, obj.grade);
	return (*this);
}

std::ostream &operator << (std::ostream &os, Bureaucrat const &b)
{
	os << "<"  << b.getName() << "> ";
	os.width(15 - b.getName().length());
	os << "Grade: " << b.getGrade() << std::endl;
	return (os);
}

// METHODS
//
std::string Bureaucrat::getName  (void) const
{
	return (this->name);
}

int      Bureaucrat::getGrade (void) const
{
	return (this->grade);
}

// DESTRUCTOR
Bureaucrat::~Bureaucrat (void)
{
	std::cout << RED << "[Bureaucrat] Destructor Called\n" <<  _R;
}
