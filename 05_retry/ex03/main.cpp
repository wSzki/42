/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/31 01:56:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void proceed(void)
{
	std::cout << _R << "\nPRESS ENTER TO CONTINUE" << std::endl;
	getchar();
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	{
		_CLEAR;
		std::cout << _R <<"To output to log file and STDOUT at the same time" << std::endl;
		std::cout << YELLOW << "\n./a.out | tee log.txt" << std::endl;
		proceed();
		_CLEAR;
	}

	Intern intern;
	Form * form;
	Bureaucrat bob("Bob", 1);

	try
	{
		form = intern.makeForm("robotomy request",     "Carlo");
		form->beSigned(bob);
		form->execute (bob);
		delete form;
		proceed();

		form = intern.makeForm("presidential request", "Paquito");
		form->beSigned(bob);
		form->execute (bob);
		delete form;
		proceed();

		form = intern.makeForm("shruberry request",    "Bobito");
		form->beSigned(bob);
		form->execute (bob);
		delete form;
		proceed();

		form = intern.makeForm("aigehiajeopjgae",    "Roberto");
		form->beSigned(bob);
		form->execute (bob);
		delete form;
		proceed();
	}
	catch (std::exception &e)
	{
		std::cout << "Intern could not create form because :" << std::endl;
		std::cout <<  e.what() << std::endl;
	}


	return (0);
}
