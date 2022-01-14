/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:59:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 21:12:05 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <iostream>
#include <cctype>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : virtual public ICharacter
{
	public:

		Character (void);
		Character (std::string name);
		Character (Character const &obj);
		~Character(void);

		Character &operator = (Character const &obj);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string name;
		AMateria *inventory[4];

	protected:

};

#endif
