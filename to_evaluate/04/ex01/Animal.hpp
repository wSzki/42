/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:45:21 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/06 15:30:39 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <iostream>
#include <cctype>

#define BLACK			"\033[0;30m"
#define RED				"\033[0;31m"
#define GREEN			"\033[0;32m"
#define ORANGE			"\033[0;33m"
#define BLUE			"\033[0;34m"
#define PURPLE			"\033[0;35m"
#define CYAN			"\033[0;36m"
#define LIGHT_GRAY		"\033[0;37m"
#define DARK_GRAY		"\033[1;30m"
#define LIGHT_RED		"\033[1;31m"
#define LIGHT_GREEN		"\033[1;32m"
#define YELLOW			"\033[1;33m"
#define LIGHT_BLUE		"\033[1;34m"
#define LIGHT_PURPLE	"\033[1;35m"
#define LIGHT_CYAN		"\033[1;36m"
#define WHITE			"\033[1;37m"
#define NO_COLOR		"\033[0m"
#define BOLD			"\e[1m"
#define _R				"\e[0m"

class Animal
{
	public:

	Animal (void);
	Animal (Animal const &);
	Animal &operator = (Animal const &);

	std::string	getType (void) const;
	void		setType (std::string type);

	virtual void makeSound(void) const;
	virtual ~Animal(void);

	protected:
	std::string type;
};









#endif
