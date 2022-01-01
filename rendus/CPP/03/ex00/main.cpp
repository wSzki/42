/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 16:15:36 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap p1("Bob");
	ClapTrap p2("Jim");

	p1.attack("Jim");
	p2.attack("Bob");
	p1.takeDamage(0);
	p2.takeDamage(0);
	p1.beRepaired(100);
	p2.beRepaired(100);

}
