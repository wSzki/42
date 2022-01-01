/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:01:13 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 19:36:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

// CONSTRUCTORS
DiamondTrap::DiamondTrap(std::string str)
{
	std::cout << "DiamondTrap - Constructor called\n";
	setName (str);
	ClapTrap::setName(str + "_clap_name");
	FragTrap::setHP   (100);
	ScavTrap::setEP   (50);
	FragTrap::setDMG  (30);
}

DiamondTrap::DiamondTrap  (void) { std::cout << "DiamondTrap - Default constructor called\n"; }
DiamondTrap::~DiamondTrap (void) { std::cout << "DiamondTrap - Destructor called\n";          }

// METHODS

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << Name;
	std::cout << " & my ClapTrap name is "  << ClapTrap::getName() << std::endl;
}

// SETTERS
void  DiamondTrap::setName(std::string str) { Name = str; }

// GETTERS
std::string DiamondTrap::getName(void) const { return (this->Name); }
