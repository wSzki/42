/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/21 19:40:00 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include <exception>


void test_1(void)
{
	std::cout << "#################### BASIC" << std::endl;
	std::cout << YELLOW "Creating 2 Bobs, one Jim, and an unknown\n" _R;
	Bureaucrat Bob("Bob", 1);
	Bureaucrat BobClone(Bob);
	Bureaucrat Jim("Jim", 99);
	Bureaucrat Unknown;

	std::cout << Bob;
	std::cout << BobClone;
	std::cout << Jim;
	std::cout << Unknown;
}

void test_2(void)
{
	std::cout << "#################### INVALID GRADES" << std::endl;
	std::cout << YELLOW "Creating Rolf with Grade -1\n";
	try
	{
		Bureaucrat Rolf("Bill", -1);
		std::cout << Rolf;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
void test_2b(void)
{
	std::cout << YELLOW "Creating Rolf with Grade -1\n";
	try
	{
		Bureaucrat Rolf("Bill", -1);
		std::cout << Rolf;
	}
	catch (std::exception &e)
	{
		std::cout << "Checking original std::exception output" << std::endl;
		std::cout << e.what() << std::endl;
	}
}

void test_3(void)
{
	std::cout << YELLOW "Creating Kenny with Grade 151\n";
	try
	{
		Bureaucrat Kenny("Kenny", 151);
		std::cout << Kenny;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_4(void)
{
	std::cout << YELLOW "Creating Bob with Grade 2 then try promoting twice\n";
	Bureaucrat Bob("Bob", 2);
	try
	{
		std::cout << Bob;
		Bob.promote();
		std::cout << Bob;
		Bob.promote();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
void test_5(void)
{
	std::cout << YELLOW "Creating Bob with Grade 149 then try demoting twice\n";
	Bureaucrat Bob("Bob", 149);
	try
	{
		std::cout << Bob;
		Bob.demote();
		std::cout << Bob;
		Bob.demote();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	test_1();
	test_2();
	test_2b();
	test_3();
	test_4();
	test_5();


	return (0);
}
