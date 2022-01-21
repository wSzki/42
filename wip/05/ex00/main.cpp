/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/19 01:32:29 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	std::cout << YELLOW "Creating 2 Bobs, one Jim, and an unknown\n" _R;
	Bureaucrat Bob("Bob", 1);
	Bureaucrat Jim("Jim", 99);
	Bureaucrat BobClone(Bob);
	Bureaucrat Unknown;

	std::cout << Bob;
	std::cout << BobClone;
	std::cout << Jim;
	std::cout << Unknown;

	std::cout << YELLOW "Creating Rolf with Grade -1\n";
	std::cout << YELLOW "Creating Joe with Grade 151\n";
	Bureaucrat Rolf("Rolf", -1);
	Bureaucrat Joe("Joe", -1);

	return (0);
}
