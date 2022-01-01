/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:50:42 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 17:52:36 by wsz              ###   ########.fr       */
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
		ClapTrap (void);
		~ClapTrap (void);

		void attack     (std::string const & target);
		void takeDamage (unsigned    int   amount);
		void beRepaired (unsigned    int   amount);

		std::string getName (void) const;
		size_t      getHP   (void) const;
		size_t      getEP   (void) const;
		size_t      getDMG  (void) const;

		void setName (std::string str);
		void setHP   (size_t      amount);
		void setEP   (size_t      amount);
		void setDMG  (size_t      amount);


	private:

		std::string Name;

		size_t Hitpoints    ;
		size_t Energy_points;
		size_t Attack_damage;

};

#endif
