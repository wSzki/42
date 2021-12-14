/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:39:50 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/14 17:45:12 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
	this->_name = name;
}
Zombie::Zombie(void)
{
}

void Zombie::announce(void)
{
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}


void Zombie::setName(std::string name)
{
	this->_name = name;
}


Zombie *newZombie(std::string name)
{
	Zombie *z = new Zombie(name);
	z->announce();
	return (z);

}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed" << std::endl;
}

void Zombie::randomChump( std::string name )
{
	Zombie::setName(name);
	Zombie::announce();
}

int        main(void)
{
	Zombie *alan;
	Zombie *robert;
	Zombie *billy;
	Zombie peter;
	Zombie jack;

	std::cout << std::endl <<  "Generating zombies...\n";
	// Stack allocation
	alan = newZombie("Alan");
	robert = newZombie("Robert");
	billy = newZombie("Billy");

	// Heap allocation
	peter.randomChump("Peter");
	jack.randomChump("Jack");

	std::cout << std::endl << "Destroying zombies...\n";
	// Anything allocated by "new" MUST be deleted
	delete alan;
	delete robert;
	delete billy;


	return (0);
}
