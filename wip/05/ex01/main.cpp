/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/22 21:44:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
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
	std::string form_name;
}	t_test;

void test_1(void)
{
	std::cout << "TEST 1\n" << "#####################################" << std::endl;
	Bureaucrat Bob("Bob", 55);
	Form form_a("Form A", 55, 1);
	Form form_b("Form B", 10, 1);
	std::cout << "Created Bob: " << Bob;
	std::cout << form_a;
	std::cout << form_b;
	try
	{
		std::cout << ORANGE << "**** Bob is trying to sign form A ****" << std::endl;
		form_a.beSigned(Bob);
		std::cout << ORANGE << "**** Form has been signed ****" << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	try
	{
		std::cout << ORANGE << "**** Bob is trying to sign form B ****" << std::endl;
		form_b.beSigned(Bob);
		std::cout << ORANGE << " **** Form has been signed ****" << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << form_a;
	std::cout << form_b;

}

void test_2(t_test *t, int i)
{
	(void)i;
	(void)t;



}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	t_test t[10];

	std::srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		t[i].bureaucrat_grade = std::rand() % 300 - 100;
		t[i].grade_to_sign    = std::rand() % 300 - 100;
		t[i].grade_to_exec    = std::rand() % 300 - 100;
	}

	test_1();
	for (int i = 0; i < 10; i++)
		test_2(t, i);

	return (0);
}
