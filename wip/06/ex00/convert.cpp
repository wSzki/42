/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 02:09:26 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/06 02:15:09 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

static void convert_char(double data)
{
	int out_of_range = false;
	if (data < 0)         out_of_range = true;
	if (data > 127)       out_of_range = true;
	if (std::isnan(data)) out_of_range = true;
	if (out_of_range == true)
	{
		std::cout << "char: Impossible" << std::endl;
		return ;
	}
	if (data >= 32 && data <= 126)
		std::cout << "char: '" << static_cast<char>(data) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void convert_int(double data)
{
	int out_of_range = false;
	if (data < std::numeric_limits<int>::min()) out_of_range = true;
	if (data > std::numeric_limits<int>::max()) out_of_range = true;
	if (std::isnan(data))                       out_of_range = true;
	if (out_of_range == true)
	{
		std::cout << "int: Impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(data) << std::endl;
}

static void convert_float(double data)
{
	int out_of_range = false;
	if(std::isinf(data) == true)
	{
		std::cout << "float: " << static_cast<float>(data) << "f" << std::endl;
		return;
	}
	if (data < std::numeric_limits<float>::min()) out_of_range = true;
	if (data > std::numeric_limits<float>::max()) out_of_range = true;
	if (data == 0.0) out_of_range = false;
	if (out_of_range == true)
	{
		std::cout << "float: Impossible" << std::endl;
		return ;
	}
	if (data == std::floor(data))
		std::cout << "float: " << static_cast<float>(data) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(data) << "f" << std::endl;
}

static void convert_double(double data)
{
	int out_of_range = false;
	if(std::isinf(data) == true)
	{
		std::cout << "double: " << static_cast<float>(data) << std::endl;
		return;
	}
	if (data < std::numeric_limits<double>::min()) out_of_range = true;
	if (data > std::numeric_limits<double>::max()) out_of_range = true;
	if (data == 0.0) out_of_range = false;
	if (out_of_range == true)
	{
		std::cout << "float: Impossible" << std::endl;
		return ;
	}
	if (data == std::floor(data) && std::isinf(data) == false)
		std::cout << "double: " << static_cast<double>(data) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(data) << std::endl;
}

void convert(double data)
{
	convert_char   (data);
	convert_int    (data);
	convert_float  (data);
	convert_double (data);
}
