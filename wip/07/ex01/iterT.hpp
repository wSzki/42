/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterT.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:48:40 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/08 01:49:56 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

template <typename T>
void printT(T const & data)
{
	std::cout << data << std::endl;
}

template <typename T>
void iter(T *array, int array_len, void (*fun_ptr)(T const & param))
{
	for (int i = 0; i < array_len; i++)
		(*fun_ptr)(array[i]);
}
