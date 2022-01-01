/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:55:24 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 19:49:59 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str) :
	Name          (str),
	Hitpoints     (10),
	Energy_points (10),
	Attack_damage (0)
{ std::cout << "Constructor called\n"; }

ClapTrap::~ClapTrap (void) { std::cout << "Destructor called\n";          }

void ClapTrap::takeDamage (unsigned int amount)
{
	std::cout << this->Name << " takes " << amount << " damage\n";
	if (amount < Hitpoints)
		Hitpoints -= amount;
	else
		Hitpoints = 0;
}

void ClapTrap::attack     (std::string const & target)
{
	std::cout << Name << " attacks " << target << ", ";
	std::cout << "causing " << Attack_damage << " points of damage" << std::endl;
}

void ClapTrap::beRepaired (unsigned int amount)
{
	if (Energy_points == 0)
		std::cout << "No energy left\n";
	else
	{
		Energy_points--;
		std::cout << this->Name << " healed " << amount << " HP\n";
		std::cout << this->Name << " energy points left " << Energy_points << "\n";
		Hitpoints += amount;
	}
}
