/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:47:58 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/07 22:48:26 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TEMPLATES_H__
#define __TEMPLATES_H__
#include <iostream>
#include <cctype>

template <typename T>
void swap (T & x, T & y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const &min (T const & x, T const & y)
{
	return (x < y ? x : y);
}

template <typename T>
T const &max (T const & x, T const & y)
{
	return (x >= y ? x : y);
}

#endif
