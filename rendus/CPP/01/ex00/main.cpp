/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:39:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/21 14:06:18 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) : _name(name)
{
}

// Void constructor
Zombie::Zombie(void) : _name("Anonymous")
{
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

	std::cout << std::endl <<  "Generating heap zombies...\n";
	// Heap allocation
	alan = Zombie::newZombie("Alan");
	robert = Zombie::newZombie("Robert");
	billy = Zombie::newZombie("Billy");

	std::cout << std::endl <<  "Generating stack zombies...\n";
	// Stack allocation
	peter.randomChump("Peter");
	jack.randomChump("Jack");

	std::cout << std::endl << "Destroying heap zombies...\n";
	// Anything allocated by "new" MUST be deleted
	delete alan;
	delete robert;
	delete billy;

	std::cout << std::endl << "Destroying stack zombies...\n";
	return (0);
}
