/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/27 15:53:02 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
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

void test(t_test *t, int i)
{

	std::cout <<  CYAN  << "###########################"    << std::endl;
	std::cout << "# TEST " << i + 1 << "/10" << std::endl;
	std::cout <<  CYAN  << "###########################"    << std::endl;
	std::cout << "Grade        : " << t[i].bureaucrat_grade << std::endl;
	std::cout << "Grade to sign: " << t[i].grade_to_sign    << std::endl;
	std::cout << "Grade to exec: " << t[i].grade_to_exec    << std::endl;
	try
	{
		Bureaucrat b("Bob",  t[i].bureaucrat_grade);
		Form       f("Form", t[i].grade_to_sign, t[i].grade_to_exec);
		std::cout << b ;
		std::cout << f;
		try
		{
			b.signForm(f);
			//f.beSigned(b);
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

	_CLEAR;
	std::srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		t[i].bureaucrat_grade = std::rand() % 200 - 35;
		t[i].grade_to_sign    = std::rand() % 200 - 35;
		t[i].grade_to_exec    = std::rand() % 200 - 35;
	}
	for (int i = 0; i < 10; i++)
		test(t, i);
	return (0);
}
