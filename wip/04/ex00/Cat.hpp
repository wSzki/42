/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:55:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/03 15:36:58 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__
#include "Animal.hpp"

class Cat : virtual public Animal
{
	public:

	Cat(void);
	~Cat(void);
	Cat (Cat const &);

	Cat &operator = (const Cat &);

	private:

	protected:

};

#endif
