/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:55:04 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/02 20:32:00 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog : virtual public Animal
{
	public:

	Dog(void);
	~Dog(void);
	Dog (Dog const &obj);

	Dog &operator = (Dog const &obj);

	private:

	protected:

};

#endif
