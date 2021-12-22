/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:20:04 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/20 16:55:46 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <cctype>
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string str);
		std::string &getType( void );
		void setType(std::string str);
	private:
		std::string type;

};

#endif
