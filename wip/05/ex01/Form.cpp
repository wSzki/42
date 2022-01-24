/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:57:04 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/22 14:53:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


#include "colors.hpp"

Form::Form (std::string name, int requiredGradeToSign, int requiredGradeToExec) :
	name                (name),
	signedStatus        (0),
	requiredGradeToSign (requiredGradeToSign),
	requiredGradeToExec (requiredGradeToExec)
{
	std::cout << GREEN "[Form] Constructor called\n" << _R;
	if (this->requiredGradeToSign > 150)
	{
		throw Form::GradeTooLowException();
	}
	if (this->requiredGradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->requiredGradeToExec > 150)
		throw Form::GradeTooLowException();
	if (this->requiredGradeToExec < 1)
		throw Form::GradeTooHighException();
}

// Copy
Form::Form(Form const &obj) :
	name                (obj.getName()),
	signedStatus        (obj.getSignedStatus()),
	requiredGradeToSign (obj.getRequiredGradeToSign()),
	requiredGradeToExec (obj.getRequiredGradeToExec())
{
	if (this == &obj)
		return ;
	std::cout << GREEN "[Form] Copy constructor called\n" << _R;
}

// OVERLOADS
Form &Form::operator = (Form const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << GREEN "[Form] Assignation operator called" << _R << std::endl;
	*this = Form(obj.name, obj.requiredGradeToSign, obj.requiredGradeToExec);
	return (*this);
}

// METHODS
std::string Form::getName                (void) const { return (this->name);                }
bool        Form::getSignedStatus        (void) const { return (this->signedStatus);        }
int         Form::getRequiredGradeToSign (void) const { return (this->requiredGradeToSign); }
int         Form::getRequiredGradeToExec (void) const { return (this->requiredGradeToExec); }

void Form::beSigned(Bureaucrat &guy)
{
	if (guy.getGrade() <= this->requiredGradeToSign)
		this->signedStatus = 1;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator << (std::ostream &o, Form &obj)
{

	o << _R << "Name: "                   << YELLOW << obj.getName()                << std::endl;
	o << _R << "Is signed: "              << YELLOW << obj.getSignedStatus()        << std::endl;
	o << _R << "Required grade to sign: " << YELLOW << obj.getRequiredGradeToSign() << std::endl;
	o << _R << "Required grade to exec: " << YELLOW << obj.getRequiredGradeToExec() << std::endl;
	return o;
}

const char * Form::GradeTooLowException::what() throw()
{
	return ("Grade too low\n");
}
const char * Form::GradeTooHighException::what() throw()
{
	return ("Grade too high\n");
}

// DESTRUCTOR
Form::~Form (void)
{
	std::cout << RED << "[Form] Destructor Called\n" <<  _R;
}
