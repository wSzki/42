/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:31:44 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/16 16:05:01 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

static void feedback(void)
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}

static void capslock(char **av)
{
	int i;
	char *str;

	i = -1;
	str = av[1];
	while (str[++i])
		str[i] = std::toupper(str[i]);
	std::cout << str << '\n';
}

static void error(void)
{
	std::cerr << "Error\nToo many arguments\n";
}

int main(int ac, char **av)
{
	if (ac == 1)
		feedback();
	if (ac == 2)
		capslock(av);
	if (ac > 2)
		error();
	return (0);
}
