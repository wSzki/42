/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:56:06 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 19:29:54 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap  (void);
		DiamondTrap  (std::string str);
		~DiamondTrap (void);

		//void attack(std::string const & target);
		void whoAmI(void);

		void setName(std::string str);
		std::string getName(void) const;

	private :
	std::string Name;
};


#endif



