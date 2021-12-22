/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 23:03:58 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/21 14:25:00 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <cstring>
void Karen::debug(void)
{
	std::cout << GREEN
		<< "[DEBUG] I love to get extra bacon for my 7XL-double-chess-triple-pickle-special-ketchup burger. I just love it !"
		<< _R << std::endl;
}
void Karen::info(void)
{
	std::cout << WHITE
		<< "[INFO] I cannot believe adding extra bacon cost more money. You don't put enough! If you did i would not have to ask for it!"
		<< _R << std::endl;
}
void Karen::warning(void)
{
	std::cout << YELLOW
		<< "[WARNING] I think I deserve to have extra bacon for free. I've been coming here for years and you just started working here last month."
		<< _R << std::endl;
}
void Karen::error(void)
{
	std::cout << RED
		<< "[ERROR] This is unacceptable, I want to speak to the manager now."
		<< _R << std::endl;
}
void Karen::complain(std::string level)
{
	int i = 0;
	std::string level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Karen::*function_pointer[4])(void);

	function_pointer[0] = &Karen::debug;
	function_pointer[1] = &Karen::info;
	function_pointer[2] = &Karen::warning;
	function_pointer[3] = &Karen::error;

	for (i = 0; i < 4; i++)
		if (level == level_list[i])
			break ;
	switch(i)
	{
		default:
							if (i > 3)
							{
								std::cout << "I am not sure how tired I am today...\n";
								break ;
							}
		case 0: 			(this->*function_pointer[i++])();
		case 1: 			(this->*function_pointer[i++])();
		case 2: 			(this->*function_pointer[i++])();
		case 3:				(this->*function_pointer[i++])();
	}
}
