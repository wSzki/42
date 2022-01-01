/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:56:06 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 18:22:09 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__
#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
	public:
		FragTrap  (std::string str);
		~FragTrap (void);
		FragTrap (void);

		void attack(std::string const & target);
		void highFivesGuys(void);
};

#endif



