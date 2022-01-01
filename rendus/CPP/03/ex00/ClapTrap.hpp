/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:50:42 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 16:55:12 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>
#include <cctype>

class ClapTrap
{
	public:

		ClapTrap  (std::string str);
		~ClapTrap (void);

		void attack     (std::string const & target);
		void takeDamage (unsigned    int   amount);
		void beRepaired (unsigned    int   amount);

	private:

		std::string Name;

		size_t Hitpoints    ;
		size_t Energy_points;
		size_t Attack_damage;

};

#endif
