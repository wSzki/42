/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:00 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 00:44:34 by wszurkow         ###   ########.fr       */
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

	//std::string getType(void) const;

	private:

	protected:

};

#endif
