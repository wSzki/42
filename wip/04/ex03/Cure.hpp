/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:00 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 00:53:09 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_H__
#define __CURE_H__
#include <iostream>
#include <cctype>
#include "AMateria.hpp"

class Cure : public virtual AMateria
{
	public:

	Cure  (void);
	Cure  (Cure const &obj);
	~Cure (void);

	Cure &operator = (Cure const &obj);

	AMateria* clone();
	AMateria* clone() const;

	//std::string getType(void) const;

	private:

	protected:

};

#endif
