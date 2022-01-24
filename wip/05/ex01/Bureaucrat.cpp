/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:23:56 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/22 15:02:51 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <exception>
#include <ostream>
#include <iomanip>

// Default
Bureaucrat::Bureaucrat (void) :
	name("Unknown"),
	grade(150)
{
	std::cout << GREEN "[Bureaucrat] Default constructor called\n" << _R;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	name(name),
	grade(grade)
{
	std::cout << GREEN "[Bureaucrat] Constructor called\n" << _R;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

// Copy
Bureaucrat::Bureaucrat(Bureaucrat const &obj) :
	name(obj.name),
	grade(obj.grade)
{
	std::cout << GREEN "[Bureaucrat] Copy constructor called\n" << _R;
	if (this == &obj)
		return ;
}

// OVERLOADS
Bureaucrat &Bureaucrat::operator = (Bureaucrat const &obj)
{
	std::cout << GREEN "[Bureaucrat] Assignation operator called" << _R << std::endl;
	if (this == &obj)
		return *this ;
	*this = obj;
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

void Bureaucrat::promote()
{
	if (this->grade -1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
	std::cout << "Promoted !" << std::endl;
}

void Bureaucrat::demote()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
	std::cout << "Demoted !" << std::endl;
}

void Bureaucrat::signForm(Form &form)
{
	if (this->grade < form.getRequiredGradeToSign())
		std::cout << this->name << " signs " << form.getName() << std::endl;
	else
		std::cout << this->name << " cannot sign " << form.getName() << " because " << std::endl;
}

// EXCEPTIONS
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// DESTRUCTOR
Bureaucrat::~Bureaucrat (void)
{
	std::cout << RED << "[Bureaucrat] Destructor Called\n" <<  _R;
}
