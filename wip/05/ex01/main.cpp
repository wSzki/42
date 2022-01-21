/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/21 20:49:52 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>


void test_1(void)
{
	Bureaucrat Bob("Bob", 55);
	Form form("Form A", 1, 1);

}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	test_1();

	return (0);
}
