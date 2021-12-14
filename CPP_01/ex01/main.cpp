/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:39:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/14 20:00:49 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name)
{
	this->_name = name;
}

// Void constructor
Zombie::Zombie(void)
{
	this->_name = "Anonymous";
}

// Destructor
Zombie::~Zombie(void)
{
	std::cout << "<"<< this->_name << "> has been destroyed" << std::endl;
}

int        main(void)
{
	Zombie *alan;
	Zombie *robert;
	Zombie *billy;
	Zombie peter;
	Zombie jack;

	std::cout << std::endl <<  "Generating stack zombies...\n";
	// Stack allocation
	alan = Zombie::newZombie("Alan");
	robert = Zombie::newZombie("Robert");
	billy = Zombie::newZombie("Billy");

	std::cout << std::endl <<  "Generating heap zombies...\n";
	// Heap allocation
	peter.randomChump("Peter");
	jack.randomChump("Jack");

	std::cout << std::endl << "Destroying stack zombies...\n";
	// Anything allocated by "new" MUST be deleted
	delete alan;
	delete robert;
	delete billy;

	// Horde generation
	std::cout << std::endl << "Generating horde...\n";
	Zombie *horde;

	// *horde points to the first zombie
	horde = Zombie::zombieHorde(10, "bomzie_");

	std::cout << std::endl << "Destroying horde...\n";
	Zombie *tmp;
	for (int i = 0; i < 10; i++)
	{
		tmp = horde->next;
		delete horde;
		horde = tmp;
	}
	std::cout << std::endl << "Destroying heap zombies...\n";
	return (0);
}
