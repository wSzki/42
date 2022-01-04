/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:55:38 by wszurkow          #+#    #+#             */
/*   Upd"ated: 2022/01/03 16:00:15 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
	public:

	Cat(void);
	~Cat(void);
	Cat (Cat const &obj);

	Cat &operator = (Cat const &obj);
	void makeSound(void) const;
	std::string getIdea() const;

	private:
	Brain *brain;

	protected:

};

#endif
