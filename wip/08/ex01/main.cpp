/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:08:06 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/16 03:06:58 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


void test_subject(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_basic()
{
	Span s(5);
	try
	{
		s.fill(5 , 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_too_much()
{
	Span s(5);
	try
	{
		s.fill(10 , 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


void test_10_000(Span s)
{
	try
	{
		s.fill(10000 , 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


int main(void)
{
	Span s(5);

	srand(time(0));

	test_subject();
	test_basic();
	//test_too_much(s);
	//test_10_000(s);


	//std::cout << "Sortest span : " << s.shortestSpan() << std::endl;
	//std::cout << "Longest span : " << s.longestSpan() << std::endl;

	return (0);
}
