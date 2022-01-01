/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 18:13:35 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\n####################\n";
	std::cout << "Creating 2 ClapTraps";
	std::cout << "\n####################\n";
	ClapTrap p1("Bob");
	ClapTrap p2("Jim");
	std::cout << "\n####################\n";

	std::cout << "Fight !";
	std::cout << "\n####################\n";
	p1.attack("Jim");
	p2.attack("Bob");
	p1.takeDamage(p2.getDMG());
	p2.takeDamage(p1.getDMG());
	p1.beRepaired(100);
	p2.beRepaired(100);

	std::cout << "\n####################\n";
	std::cout << "Creating 2 ScavTraps";
	std::cout << "\n####################\n";
	ScavTrap p3("Joe");
	ScavTrap p4("Xyz");

	std::cout << "\n####################\n";
	std::cout << "Fight !";
	std::cout << "\n####################\n";
	p3.attack("Xyz");
	p4.attack("Joe");
	p3.guardGate();
	p4.guardGate();
	p3.takeDamage(p4.getDMG());
	p4.takeDamage(p3.getDMG());
	p3.beRepaired(100);
	p4.beRepaired(100);

	std::cout << "\n####################\n";
	std::cout << "Destroying everyone";
	std::cout << "\n####################\n";
}
