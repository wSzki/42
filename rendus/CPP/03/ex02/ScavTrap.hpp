/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:56:06 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 18:13:48 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap  (std::string str);
		~ScavTrap (void);
		ScavTrap (void);

		void attack(std::string const & target);
		void guardGate();
};

#endif



