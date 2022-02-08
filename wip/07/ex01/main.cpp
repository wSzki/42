/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:52:12 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/08 01:50:06 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iterT.hpp"

int main()
{
	int   array_int     [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	char  array_char    [06] = {'a', 'b', 'c', 'd', 'e', 'f'};
	float array_float   [02] = {-42.21, 21.42};
	void *array_ptr     [03] = {array_int, array_char, array_float};

	std::cout << "\n# INT" << std::endl;
	iter(array_int,    10, printT);
	std::cout << "\n# CHAR" << std::endl;
	iter(array_char,   06, printT);
	std::cout << "\n# FLOAT" << std::endl;
	iter(array_float,  02, printT);
	std::cout << "\n# ADRESS" << std::endl;
	iter(array_ptr,    03, printT);
	std::cout << std::endl;

	return (0);
}
