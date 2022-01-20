/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:45:21 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:14:51 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__
#include <iostream>
#include <cctype>


class WrongAnimal
{
	public:

	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal (WrongAnimal const &);

	WrongAnimal &operator = (WrongAnimal const &);
	std::string getType(void) const;
	void setType (std::string type);
	void makeSound(void) const;

	private:

	protected:

	std::string type;

};









#endif
