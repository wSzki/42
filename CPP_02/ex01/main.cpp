/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:05:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/23 21:38:33 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed (1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "a is " << b << std::endl;
	std::cout << "a is " << c << std::endl;
	std::cout << "a is " << d << std::endl;

	std::cout << "a is " << a.toInt() << "as integer" << std::endl;
	std::cout << "a is " << b.toInt() << "as integer" << std::endl;
	std::cout << "a is " << c.toInt() << "as integer" << std::endl;
	std::cout << "a is " << d.toInt() << "as integer" << std::endl;

	return (0);
}
