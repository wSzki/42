/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:19:35 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/14 17:42:25 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie {
	public:
		static Zombie *newZombie(std::string name);
		void randomChump( std::string name );
		void announce(void);
		void setName(std::string name);

		Zombie(std::string name);
		Zombie(void);
		~Zombie(void );

	private:
		std::string _name;
};

#endif
