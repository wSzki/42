/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:22:08 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/03 19:22:10 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__
#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	public:

	WrongCat(void);
	~WrongCat(void);
	WrongCat (WrongCat const &obj);

	WrongCat &operator = (WrongCat const &obj);
	void makeSound(void) const;

	private:

	protected:

};

#endif
