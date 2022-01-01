/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:55:04 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/30 12:57:32 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include <iostream>
#include <cctype>

class Dog : public Animal
{
	public:
		Dog(void);
		~Dog(void);
	private:
	protected:
};

#endif
