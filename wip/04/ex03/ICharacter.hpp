/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:07:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/06 17:22:05 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_H__
#define __ICHARACTER_H__
#include <iostream>
#include <cctype>
#include "AMateria.hpp"

class ICharacter
{
	public:

		ICharacter(void);
		ICharacter (ICharacter const &obj);

		ICharacter &operator = (ICharacter const &obj);

		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

	private:

	protected:

};

#endif
