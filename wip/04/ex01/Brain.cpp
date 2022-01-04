/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:25:09 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/04 02:27:01 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstdlib>

Brain::Brain  (void)
{
	std::cout << "[Brain] Default constructor called\n";
	std::string idea_list[] = {"eat", "sleep", "mate"};
	ideas[0] = idea_list[rand() % 3];
}

Brain::Brain(Brain const &obj)
{
	std::cout << "[Brain] Copy constructor called\n";
	*this = obj;
}

Brain &Brain::operator = (Brain const &obj)
{
	std::cout << "[Brain] Assignation operator called" << std::endl;
	*this = obj;
	return (*this);
}

Brain::~Brain (void)
{
	std::cout << "[Brain] Destructor Called\n";
}
