/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:00 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/14 16:39:07 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_H__
#define __ICE_H__
#include <iostream>
#include <cctype>
#include "AMateria.hpp"

class Ice : public virtual AMateria
{
	public:

	Ice  (void);
	Ice  (Ice const &obj);
	~Ice (void);

	Ice &operator = (Ice const &obj);

	AMateria* clone();
	AMateria* clone() const;

	void use(ICharacter& target);

	private:

	protected:

};

#endif
