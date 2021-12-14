/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:53:43 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/14 19:58:29 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	int i = 0;
	std::string z_name;
	Zombie *z[N];

	z_name = name + std::to_string(0) ;
	z[0] = newZombie(z_name);
	while (++i < N)
	{
		z_name = name + std::to_string(i) ;
		z[i] = newZombie(z_name);
		z[i - 1]->next = z[i];
	}
	z[i - 1]->next = z[i];
	return (*z);
}
