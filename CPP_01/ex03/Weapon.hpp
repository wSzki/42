/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:20:04 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/15 14:31:26 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>

class Weapon
{
	static Weapon& getType() : ->type;
	{
		std::cout << type;
	}
	std::string type;
};



#endif
