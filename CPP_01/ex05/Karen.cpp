/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 23:03:58 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/21 00:13:05 by wszurkow         ###   ########.fr       */
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
	void (Karen::*function_pointer[256])(void);

	std::memset(function_pointer, 0, 256);
	function_pointer[(int)*("DEBUG")] = &Karen::debug;
	function_pointer[(int)*("INFO")] = &Karen::info;
	function_pointer[(int)*("WARNING")] = &Karen::warning;
	function_pointer[(int)*("ERROR")] = &Karen::error;
	(this->*function_pointer[(int)level[0]])();
}
