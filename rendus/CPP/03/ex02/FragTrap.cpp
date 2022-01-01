/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:01:13 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 18:21:57 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// CONSTRUCTORS
FragTrap::FragTrap(std::string str)
{
	std::cout << "FragTrap - Constructor called\n";
	setName (str);
	setHP   (100);
	setEP   (100);
	setDMG  (30);
}

FragTrap::FragTrap  (void) { std::cout << "FragTrap - Default constructor called\n"; }
FragTrap::~FragTrap (void) { std::cout << "FragTrap - Destructor called\n";          }

// METHODS
void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << getName() << " attacks " << target << ", ";
	std::cout << "causing " << getDMG() << " points of damage" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap wants to high five someone\n";
}

