/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:25:09 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:42:17 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstdlib>
#include <string>

Brain::Brain  (void)
{
	std::cout << "[Brain] Default constructor called\n";
	std::string ideaList[] = {
		"eat",
		"sleep",
		"mate",
		"run",
		"kill",
		"die",
		"play",
		"drink"
	};
	for (int i = 0; i < 100; i++)
		ideas[i] = ideaList[rand() % 8];
}

Brain::Brain(Brain const &obj)
{
	std::cout << "[Brain] Copy constructor called\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
}

Brain &Brain::operator = (Brain const &obj)
{
	std::cout << "[Brain] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return (*this);
}

Brain::~Brain (void)
{
	std::cout << "[Brain] Destructor Called\n";
}

std::string const Brain::getIdea(int i) const
{
	return (ideas[i]);
}

void Brain::setIdea(std::string str, int i)
{
	(void)str;
	(void)i;
	this->ideas[i] = str;
}
