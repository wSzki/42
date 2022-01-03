/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:45:21 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/02 20:49:52 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <iostream>
#include <cctype>


class Animal
{
	public:

	Animal(void);
	~Animal(void);
	Animal (Animal const &);

	Animal &operator = (Animal const &);
	std::string getType(void) const;
	void setType (std::string type);
	void makeSound(void) const;

	private:

	protected:

	std::string type;

};









#endif
