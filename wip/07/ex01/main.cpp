/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:52:12 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/07 23:15:22 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


	template <typename T>
void t_print(T const & data)
{
	std::cout << data << std::endl;
}

	template <typename T>
void iter(T *array, int array_len, void (*fun_ptr)(T const & param))
{
	for (int i = 0; i < array_len; i++)
		(*fun_ptr)(array[i]);
}

int main()
{
	int   array_int     [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	char  array_char    [06] = {'a', 'b', 'c', 'd', 'e', 'f'};
	float array_float   [02] = {-42.21, 21.42};
	void *array_ptr     [03] = {array_int, array_char, array_float};
	std::cout << "\n# INT" << std::endl;
	iter(array_int,    10, t_print);
	std::cout << "\n# CHAR" << std::endl;
	iter(array_char,   06, t_print);
	std::cout << "\n# FLOAT" << std::endl;
	iter(array_float,  02, t_print);
	std::cout << "\n# ADRESS" << std::endl;
	iter(array_ptr,    03, t_print);
	std::cout << std::endl;

	return (0);
}
