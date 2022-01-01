/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:06:34 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/29 19:33:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

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
	std::cout << "Creating 2 FragTraps";
	std::cout << "\n####################\n";
	FragTrap p5("AAA");
	FragTrap p6("BBB");

	std::cout << "\n####################\n";
	std::cout << "Fight !";
	std::cout << "\n####################\n";
	p5.attack("BBB");
	p6.attack("AAA");
	p5.highFivesGuys();
	p6.highFivesGuys();
	p5.takeDamage(p6.getDMG());
	p6.takeDamage(p5.getDMG());
	p5.beRepaired(100);
	p6.beRepaired(100);

	std::cout << "\n####################\n";
	std::cout << "Creating 2 DiamondTraps";
	std::cout << "\n####################\n";
	DiamondTrap p7("DDD");
	DiamondTrap p8("EEE");

	std::cout << "\n####################\n";
	std::cout << "Fight !";
	std::cout << "\n####################\n";
	p7.whoAmI();
	p8.whoAmI();
	p7.guardGate();
	p8.guardGate();
	p7.highFivesGuys();
	p8.highFivesGuys();
	p7.ScavTrap::attack("EEE");
	p8.ScavTrap::attack("DDD");
	p7.takeDamage(p8.getDMG());
	p8.takeDamage(p7.getDMG());
	p7.beRepaired(100);
	p8.beRepaired(100);

	std::cout << "\n####################\n";
	std::cout << "Destroying everyone";
	std::cout << "\n####################\n";
}
