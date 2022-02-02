/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:25:31 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/02 19:33:04 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "colors.hpp"
#include <ctime>
#include <cstdlib>

#define RRF RobotomyRequestForm

// Default
RRF::RRF (void):
	Form("RobotomyRequestForm", 72, 45),
	target("")
{
	std::cout << GREEN "[RRF] Default constructor called\n" << _R;
}

RRF::RRF  (std::string target) :
	Form("RobotomyRequestForm", 72, 45),
	target(target)
{
	std::cout << GREEN "[RRF] Constructor called\n" << _R;
}


// Copy
RRF::RRF(RRF const &obj):
	Form("RobotomyRequestForm", 72, 45),
	target(obj.target)
{
	std::cout << GREEN "[RRF] Copy constructor called\n" << _R;
	if (this == &obj)
		return ;
	*this = obj;
}

// OVERLOADS
RRF &RRF::operator = (RRF const &obj)
{
	std::cout << GREEN "[RRF] Assignation operator called" << _R << std::endl;
	if (this == &obj)
		return (*this);
	*this = RRF(obj);
	return (*this);
}

// METHODS
void RRF::execute(Bureaucrat const & executor) const
{
	this->checkIfSigned();
	if (executor.getGrade() <= this->getRequiredGradeToExec())
	{
		std::srand(time(0));
		std::cout << CYAN << "*** DRILLING NOISES ***" << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << CYAN << this->target << " has been successfully robotomized" << std::endl;
		else
			std::cout << CYAN << "Robotomy failed" << std::endl;
		std::cout << LIGHT_GREEN << "********************************************************" << std::endl;
		std::cout << LIGHT_GREEN << "*** " << this->getName() << " executed successfully " << "by " << executor.getName() << " ***" << std::endl;
		std::cout << LIGHT_GREEN << "********************************************************" << std::endl;
	}
	else
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because ";
		throw Bureaucrat::GradeTooLowException();
	}
}

// DESTRUCTOR
RRF::~RRF (void)
{
	std::cout << RED << "[RRF] Destructor Called\n" <<  _R;
}
