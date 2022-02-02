/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/02 19:46:46 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

typedef struct s_test
{
	int         bureaucrat_grade;
	int         grade_to_sign;
	int         grade_to_exec;
}	t_test;


void test_shrubbery(t_test *t, int i)
{
	try
	{
		std::cout <<  CYAN  << "###########################"    << std::endl;
		std::cout << "# SHRUBBERY TEST " << i + 1 << "/10"      << std::endl;
		std::cout <<  CYAN  << "###########################"    << std::endl;
		std::cout << "Grade        : " << t[i].bureaucrat_grade << std::endl;

		Bureaucrat bob("Bob", t[i].bureaucrat_grade);
		ShrubberyCreationForm form("ascii_tree");
		std::cout << form;
		try
		{
			bob.signForm(form);
			bob.executeForm(form);
			std::cout << form;
		}
		catch (std::exception &e)
		{
			std::cout << LIGHT_RED << "[ERROR] " << _R << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << LIGHT_RED << "[ERROR] " << _R << e.what() << std::endl;
	}
	std::cout << "\nPRESS ENTER TO CONTINUE" << std::endl;
	getchar();
	_CLEAR;
}
void test_robotomy(t_test *t, int i)
{
	try
	{
		std::cout <<  LIGHT_PURPLE  << "###########################"    << std::endl;
		std::cout << "# ROBOTOMY TEST " << i + 1 << "/10"               << std::endl;
		std::cout <<  LIGHT_PURPLE  << "###########################"    << std::endl;
		std::cout << "Grade        : " << t[i].bureaucrat_grade << std::endl;
		Bureaucrat bob("Bob", t[i].bureaucrat_grade);
		RobotomyRequestForm form("Human");
		std::cout << form;
		try
		{
			bob.signForm(form);
			bob.executeForm(form);
			std::cout << form;
		}
		catch (std::exception &e)
		{
			std::cout << LIGHT_RED << "[ERROR] " << _R << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << LIGHT_RED << "[ERROR] " << _R << e.what() << std::endl;
	}
	std::cout << "\nPRESS ENTER TO CONTINUE" << std::endl;
	getchar();
	_CLEAR;
}

void test_presidential(t_test *t, int i)
{
	try
	{
		std::cout <<  LIGHT_BLUE << "###########################"    << std::endl;
		std::cout << "# PRESIDENTIAL TEST " << i + 1 << "/10"               << std::endl;
		std::cout <<  LIGHT_BLUE  << "###########################"    << std::endl;
		std::cout << "Grade        : " << t[i].bureaucrat_grade << std::endl;
		Bureaucrat bob("Bob", t[i].bureaucrat_grade);
		PresidentialPardonForm form("Banana");
		std::cout << form;
		try
		{
			bob.signForm(form);
			bob.executeForm(form);
			std::cout << form;
		}
		catch (std::exception &e)
		{
			std::cout << LIGHT_RED << "[ERROR] " << _R << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << LIGHT_RED << "[ERROR] " << _R << e.what() << std::endl;
	}
	std::cout << "\nPRESS ENTER TO CONTINUE" << std::endl;
	getchar();
	_CLEAR;
}
void test_unsigned(t_test *t, int i)
{
	try
	{
		std::cout <<  LIGHT_PURPLE << "###########################"    << std::endl;
		std::cout << "# UNSIGNED TEST " << i + 1 << "/5"               << std::endl;
		std::cout <<  LIGHT_PURPLE  << "###########################"    << std::endl;
		std::cout << "Grade        : " << t[i].bureaucrat_grade << std::endl;
		Bureaucrat bob("Bob", t[i].bureaucrat_grade);

		//PresidentialPardonForm form("Banana");
		ShrubberyCreationForm  form("Orange");
		//RobotomyRequestForm    form("Apple");
		std::cout << form;
		try
		{
			form.execute(bob);
			std::cout << form;
		}
		catch (std::exception &e)
		{
			std::cout << LIGHT_RED << "[ERROR] " << _R << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << LIGHT_RED << "[ERROR] " << _R << e.what() << std::endl;
	}
	std::cout << "\nPRESS ENTER TO CONTINUE" << std::endl;
	getchar();
	_CLEAR;
}
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	t_test t[10];

	{
		_CLEAR;
		std::cout << _R <<"To output to log file and STDOUT at the same time" << std::endl;
		std::cout << YELLOW << "\n./a.out | tee log.txt" << std::endl;
		std::cout << _R << "\nPRESS ENTER TO CONTINUE" << std::endl;
		getchar();
		_CLEAR;
	}

	std::srand(time(0));

	for (int i = 0; i < 10; i++)
		t[i].bureaucrat_grade = std::rand() % 20 + 130;
	for (int i = 0; i < 10; i++)
		test_shrubbery(t, i);

	for (int i = 0; i < 10; i++)
		t[i].bureaucrat_grade = std::rand() % 100;
	for (int i = 0; i < 10; i++)
		test_robotomy(t, i);

	for (int i = 0; i < 10; i++)
		t[i].bureaucrat_grade = std::rand() % 30;
	for (int i = 0; i < 10; i++)
		test_presidential(t, i);

	for (int i = 0; i < 5; i++)
		t[i].bureaucrat_grade = std::rand() % 150;
	for (int i = 0; i < 5; i++)
		test_unsigned(t, i);

	{
		std::cout << "\n*** END OF TESTS *** \n" ;
		std::cout << "PRESS ENTER TO EXIT" << std::endl;
		getchar();
		_CLEAR;
	}

	return (0);
}
