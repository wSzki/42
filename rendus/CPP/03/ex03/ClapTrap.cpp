/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:55:24 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 19:52:05 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// CONSTRUCTORS
ClapTrap::ClapTrap(std::string str) :
	Name          (str),
	Hitpoints     (10),
	Energy_points (10),
	Attack_damage (0)
{ std::cout << "ClapTrap - Constructor called\n"; }

ClapTrap::ClapTrap  (void) { std::cout << "ClapTrap - Default constructor called\n"; }
ClapTrap::~ClapTrap (void) { std::cout << "ClapTrap - Destructor called\n";          }

// SETTERS
void ClapTrap::setName (std::string str)    { Name          = str;    }
void ClapTrap::setHP   (size_t      amount) { Hitpoints     = amount; }
void ClapTrap::setEP   (size_t      amount) { Energy_points = amount; }
void ClapTrap::setDMG  (size_t      amount) { Attack_damage = amount; }

// GETTERS
std::string ClapTrap::getName (void) const { return (Name);          }
size_t      ClapTrap::getHP   (void) const { return (Hitpoints);     }
size_t      ClapTrap::getEP   (void) const { return (Energy_points); }
size_t      ClapTrap::getDMG  (void) const { return (Attack_damage); }

// METHODS
void ClapTrap::takeDamage (unsigned int amount)
{
	std::cout << Name << " takes " << amount << " damage\n";
	if (amount < Hitpoints)
		Hitpoints -= amount;
	else
		Hitpoints = 0;
}

void ClapTrap::attack     (std::string const & target)
{
	std::cout << Name << " attacks " << target << ", ";
	std::cout << "ClapTrap " << Name << " attacks " << target << ", ";
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
