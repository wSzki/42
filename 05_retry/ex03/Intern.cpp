/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:07:19 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/31 01:59:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Intern.hpp"

#include "colors.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Form * makeShruberry    (std::string target) { return (new ShrubberyCreationForm  (target)); }
Form * makePresidential (std::string target) { return (new PresidentialPardonForm (target)); }
Form * makeRobotomy     (std::string target) { return (new RobotomyRequestForm    (target)); }

// DEFAULT
Intern::Intern (void)
{
	std::cout << GREEN "[Intern] Default constructor called\n" << _R;

	this->knowm_forms [0] = "robotomy request";
	this->knowm_forms [1] = "presidential request";
	this->knowm_forms [2] = "shruberry request";

	this->createForm  [0] = makeRobotomy;
	this->createForm  [1] = makePresidential;
	this->createForm  [2] = makeShruberry;

}
// COPY
Intern::Intern(Intern const &obj)
{
	std::cout << GREEN "[Intern] Copy constructor called\n" << _R;
	if (this == &obj)
		return ;
	*this = obj;
}

// OVERLOADS
Intern &Intern::operator = (Intern const &obj)
{
	std::cout << GREEN "[Intern] Assignation operator called" << _R << std::endl;
	if (this == &obj)
		return (*this);
	*this = obj;
	return (*this);
}

// METHODS

const char * Intern::UnknownFormException::what() const throw()
{
	return ("Form name unknowm");
}

Form * Intern::makeForm(std::string form_name, std::string target)
{
	for (int i = 0; i < 3; i++)
		if (form_name == this->knowm_forms[i])
		{
			std::cout << PURPLE << "Intern has successfully created " << form_name << std::endl;
			return (this->createForm[i](target));
		}
	throw Intern::UnknownFormException();
}

// DESTRUCTOR
Intern::~Intern (void)
{
	std::cout << RED << "[Intern] Destructor Called\n" <<  _R;
}
