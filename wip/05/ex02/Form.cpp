/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:57:04 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/25 18:02:34 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


#include "Bureaucrat.hpp"
#include "colors.hpp"

Form::Form (std::string name, int requiredGradeToSign, int requiredGradeToExec) :
	name                (name),
	signedStatus        (0),
	requiredGradeToSign (requiredGradeToSign),
	requiredGradeToExec (requiredGradeToExec)
{
	std::cout << GREEN "[Form] Constructor called\n" << _R;
	if (this->requiredGradeToSign > 150)
		throw Form::GradeTooLowException();
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
	std::cout << GREEN "[Form] Copy constructor called\n" << _R;
	if (this == &obj)
		return ;
	*this = obj;
}

// OVERLOADS
Form &Form::operator = (Form const &obj)
{
	std::cout << GREEN "[Form] Assignation operator called" << _R << std::endl;
	if (this == &obj)
		return (*this);
	//*this = Form(obj.name, obj.requiredGradeToSign, obj.requiredGradeToExec);
	*this = obj;
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
	{
		this->signedStatus = 1;
		std::cout << YELLOW << "********************************" << std::endl;
		std::cout << YELLOW << "*** FORM SIGNED SUCCESSFULLY ***" << std::endl;
		std::cout << YELLOW << "********************************" << std::endl;
		std::cout << *this;
	}
	else
	{
		std::cout << guy.getName() << " cannot sign " << this->name << " because ";
		std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream & operator << (std::ostream &o, Form &obj)
{

	o << _R << "Form name:              " << ORANGE << obj.getName()                << std::endl;
	o << _R << "Is signed:              " << ORANGE << obj.getSignedStatus()        << std::endl;
	o << _R << "Required grade to sign: " << ORANGE << obj.getRequiredGradeToSign() << std::endl;
	o << _R << "Required grade to exec: " << ORANGE << obj.getRequiredGradeToExec() << std::endl;
	o << _R;
	return o;
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}
const char * Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

// DESTRUCTOR
Form::~Form (void)
{
	std::cout << RED << "[Form] Destructor Called\n" <<  _R;
}
