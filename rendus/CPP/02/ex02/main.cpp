/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:05:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/28 16:18:08 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ <<  std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	std::cout << "############## TEST A #################\n";
	Fixed tmp;
	Fixed x = 3;
	Fixed y = 2;
	std::cout << "x = " << x.toInt() << std::endl;
	std::cout << "y = " << y.toInt() << std::endl;
	std::cout << std::endl;
	tmp = x + y;
	std::cout << "a + b = "<< tmp.toInt() << std::endl;
	tmp = x / y;
	std::cout << "a / b = "<< tmp.toFloat() << std::endl;
	tmp = x * y;
	std::cout << "a * b = "<< tmp.toFloat() << std::endl;
	tmp = x - y;
	std::cout << "a - b = "<< tmp.toInt() << std::endl;
	std::cout << "############## TEST B #################\n";
	x = 3;
	Fixed z(0.5f);
	std::cout << "x = " << x.toInt() << std::endl;
	std::cout << "z = " << z.toFloat() << std::endl;
	std::cout << std::endl;
	tmp = x + z;
	std::cout << "a + b = "<< tmp.toInt() << std::endl;
	tmp = x / z;
	std::cout << "a / b = "<< tmp.toFloat() << std::endl;
	tmp = x * z;
	std::cout << "a * b = "<< tmp.toFloat() << std::endl;
	tmp = x - z;
	std::cout << "a - b = "<< tmp.toInt() << std::endl;
	std::cout << "############## TEST C #################\n";
	x = 3;
	y = 2;

	std::cout << "x = " << x.toInt() << std::endl;
	std::cout << "y = " << y.toInt() << std::endl;
	std::cout << std::endl;

	std::cout << "x < y ? "  << (x <  y) << std::endl;
	std::cout << "x > y ? "  << (x >  y) << std::endl;
	std::cout << "x <= y ? " << (x <= y) << std::endl;
	std::cout << "x >= y ? " << (x >= y) << std::endl;
	std::cout << "x == y ? " << (x == y) << std::endl;
	std::cout << "x != y ? " << (x != y) << std::endl;

	std::cout << "############## TEST D #################\n";
	x = 3;
	y = 3;

	std::cout << "x = " << x.toInt() << std::endl;
	std::cout << "y = " << y.toInt() << std::endl;
	std::cout << std::endl;

	std::cout << "x < y ? "  << (x <  y) << std::endl;
	std::cout << "x > y ? "  << (x >  y) << std::endl;
	std::cout << "x <= y ? " << (x <= y) << std::endl;
	std::cout << "x >= y ? " << (x >= y) << std::endl;
	std::cout << "x == y ? " << (x == y) << std::endl;
	std::cout << "x != y ? " << (x != y) << std::endl;

	std::cout << "############## TEST E #################\n";
	x = 3;
	y = 3;
	std::cout << "x = " << x.getRawBits() << std::endl;
	std::cout << "y = " << y.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << "x++ = " << (x++).getRawBits() << std::endl;
	std::cout << "y++ = " << (y++).getRawBits() << std::endl;
	std::cout << "++x = " << (++x).getRawBits() << std::endl;
	std::cout << "++y = " << (++y).getRawBits() << std::endl;
	std::cout << "x-- = " << (x--).getRawBits() << std::endl;
	std::cout << "y-- = " << (y--).getRawBits() << std::endl;
	std::cout << "--x = " << (--x).getRawBits() << std::endl;
	std::cout << "--y = " << (--y).getRawBits() << std::endl;

	return 0;
}
