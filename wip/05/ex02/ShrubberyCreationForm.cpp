/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:25:31 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/25 17:54:40 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"
#include <fstream>
#define SCB ShrubberyCreationForm

// Default
SCB::SCB (void):
	Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << GREEN "[SCB] Default constructor called\n" << _R;
}

SCB::SCB  (std::string target) :
	Form("ShrubberyCreationForm", 145, 137),
	target(target)
{
	std::cout << GREEN "[SCB] Constructor called\n" << _R;
}


// Copy
SCB::SCB(SCB const &obj):
	Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << GREEN "[SCB] Copy constructor called\n" << _R;
	if (this == &obj)
		return ;
	*this = obj;
}

// OVERLOADS
SCB &SCB::operator = (SCB const &obj)
{
	std::cout << GREEN "[SCB] Assignation operator called" << _R << std::endl;
	if (this == &obj)
		return (*this);
	*this = obj;
	return (*this);
}

// METHODS
void SCB::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getRequiredGradeToExec())
	{
		std::ofstream file;
		std::string str = this->target + "_shruberry";
		file.open(str.c_str());
		file <<
"                              '.,\n"
"                              'b      *\n"
"                               '$    #.\n"
"                                $:   #:\n"
"                                *#  @):\n"
"                                :@,@):   ,.**:'\n"
"                      ,         :@@*: ..**'\n"
"                       '#o.    .:(@'.@*''\n"
"                          'bq,..:,@@*'   ,*\n"
"                          ,p$q8,:@)'  .p*'\n"
"                         '    '@@Pp@@*'\n"
"                               Y7'.'\n"
"                              :@):.\n"
"                             .:@:'.\n"
"                           .::(@:.      -Sam Blumenstein-\n";
		file.close();
	}
	else
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because ";
		throw Bureaucrat::GradeTooLowException();
	}
}

// DESTRUCTOR
SCB::~SCB (void)
{
	std::cout << RED << "[SCB] Destructor Called\n" <<  _R;
}
