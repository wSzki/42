/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 23:17:03 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/21 03:55:33 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <cstdint>

int main(int ac, char **av, char **env)
{
	(void)env;

	Karen Karen;
	if (ac == 2)
		Karen.complain(av[1]);
	else
		std::cerr << RED << "Error\n" << _R << "Invalid number of arguments\n";
	return (0);
}
