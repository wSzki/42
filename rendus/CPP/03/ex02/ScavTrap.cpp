/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:01:13 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 18:14:11 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// CONSTRUCTORS
ScavTrap::ScavTrap(std::string str)
{
	std::cout << "ScavTrap - Constructor called\n";
	setName (str);
	setHP   (100);
	setEP   (50);
	setDMG  (20);
}

ScavTrap::ScavTrap  (void) { std::cout << "ScavTrap - Default constructor called\n"; }
ScavTrap::~ScavTrap (void) { std::cout << "ScavTrap - Destructor called\n";          }

// METHODS
void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", ";
	std::cout << "causing " << getDMG() << " points of damage" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap have entered in gatekeeper mode\n";
}

