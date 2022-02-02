/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:25:31 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/02 19:27:41 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "colors.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>
#define PPF PresidentialPardonForm

// Default
PPF::PPF (void):
	Form("PresidentialPardonForm", 25, 5),
	target("")
{
	std::cout << GREEN "[PPF] Default constructor called\n" << _R;
}

PPF::PPF  (std::string target) :
	Form("PresidentialPardonForm", 25, 5),
	target(target)
{
	std::cout << GREEN "[PPF] Constructor called\n" << _R;
}

// Copy
PPF::PPF(PPF const &obj):
	Form("PresidentialPardonForm", 25, 5),
	target(obj.target)
{
	std::cout << GREEN "[PPF] Copy constructor called\n" << _R;
	if (this == &obj)
		return ;
}

// OVERLOADS
PPF &PPF::operator = (PPF const &obj)
{
	std::cout << GREEN "[PPF] Assignation operator called" << _R << std::endl;
	if (this == &obj)
		return (*this);
	*this = PPF(obj);
	return (*this);
}

// METHODS
void PPF::execute(Bureaucrat const & executor) const
{
	this->checkIfSigned();
	if (executor.getGrade() <= this->getRequiredGradeToExec())
	{
		std::srand(time(0));
			std::cout << CYAN << this->target << " has been pardonned by Zafod Beeblebrox" << std::endl;
		std::cout << LIGHT_GREEN << "***********************************************************" << std::endl;
		std::cout << LIGHT_GREEN << "*** " << this->getName() << " executed successfully " << "by " << executor.getName() << " ***" << std::endl;
		std::cout << LIGHT_GREEN << "***********************************************************" << std::endl;
	}
	else
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because ";
		throw Bureaucrat::GradeTooLowException();
	}
}

// DESTRUCTOR
PPF::~PPF (void)
{
	std::cout << RED << "[PPF] Destructor Called\n" <<  _R;
}
