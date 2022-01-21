/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:57:04 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/21 20:59:48 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


#include "colors.hpp"

Form::Form (std::string name, int requiredGradeToSign, int requiredGradeToExec) :
	name                (name),
	signedStatus        (0),
	requiredGradeToExec (requiredGradeToExec),
	requiredGradeToSign (requiredGradeToSign)
{
	std::cout << GREEN "[Form] Constructor called\n" << _R;
}

// Copy
Form::Form(Form const &obj) :
	name                (obj.getName()),
	signedStatus        (obj.getSignedStatus()),
	requiredGradeToExec (obj.getRequiredGradeToExec()),
	requiredGradeToSign (obj.getRequiredGradeToSign())
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

void Form::beSigned(Bureaucrat guy)
{
	if (guy.getGrade() <= this->requiredGradeToSign)
		this->signedStatus = 1;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator << (std::ostream &o, Form obj)
{

	o << "FORM\n"                   << "#####"                      << std::endl;
	o << "Name: "                   << obj.getName()                << std::endl;
	o << "Is signed: "              << obj.getSignedStatus()        << std::endl;
	o << "Required grade to sign: " << obj.getRequiredGradeToSign() << std::endl;
	o << "Required grade to exec: " << obj.getRequiredGradeToExec() << std::endl;
	return o;
}

// DESTRUCTOR
Form::~Form (void)
{
	std::cout << RED << "[Form] Destructor Called\n" <<  _R;
}
