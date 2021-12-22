/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:20:41 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/20 16:57:22 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// CONSTRUCTOR, DESTRUCTOR //////////////

//	HUMAN A
HumanA::HumanA(std::string str, Weapon &weapon) : name(str), weapon(weapon)
{
}
//	HUMAN B
HumanB::HumanB(std::string str) : name(str)
{
}
// WEAPON
Weapon::Weapon(std::string str)
{
	Weapon::setType(str);
}

// METHODS ///////////////////////////////

// HUMAN A
void HumanA::attack(void)
{
	std::cout
		<< HumanA::name
		<< " attacks with his "
		<< HumanA::weapon.getType()
		<< std::endl;
}

// HUMAN B
void HumanB::attack(void)
{
	std::cout
		<< HumanB::name
		<< " attacks with his "
		<< HumanB::weapon->getType()
		<< std::endl;
}
void HumanB::setWeapon(Weapon &w)
{
	HumanB::weapon = &w;
}

// WEAPON
std::string &Weapon::getType(void)
{
	std::string &ref = Weapon::type;
	return (ref);
}
void	Weapon::setType(std::string str)
{
	Weapon::type = str;
}

int main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
