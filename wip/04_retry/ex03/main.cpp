/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:03:58 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/17 15:32:48 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "colors.hpp"

#include "AMateria.hpp"
#include "MateriaSource.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

#define ADD_WEAPON_TO_POOL learnMateria
#define TAKE_FROM_POOL     createMateria

int main()
{

	std::cout << _R << "######################### SINGLE MATERIA #####################\n";
	AMateria *obj = new Ice();
	std::cout << _R << obj->getType() << std::endl;
	delete obj;


	std::cout << _R << "######################### MAIN FROM SUBJECT #####################\n";
	// Creating empty array[4]
	IMateriaSource* src = new MateriaSource();

	// Adding materia to array index [0] & [1]
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Creating new character
	ICharacter* me = new Character("me");

	// Creating tmp pointer to store individual newly created materias
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Creating bob
	ICharacter* bob = new Character("bob");
	std::cout << _R;
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << _R << "\n ###################### ADDITIONAL TESTS ##################################\n";

	IMateriaSource *weapon_pool = new MateriaSource();
	weapon_pool->ADD_WEAPON_TO_POOL(new Ice());
	weapon_pool->ADD_WEAPON_TO_POOL(new Cure());

	ICharacter *Jim = new Character("Jim");
	ICharacter *Ron = new Character("Ron");

	Jim->equip(weapon_pool->TAKE_FROM_POOL("ice"));
	Ron->equip(weapon_pool->TAKE_FROM_POOL("cure"));

	std::cout << _R << "####################\n";
	std::cout << _R << "# Basic valid test #\n";
	std::cout << _R << "####################\n";
	std::cout << "[Jim]\n";
	Jim->use(0, *Ron);

	std::cout << "[Ron]\n";
	Ron->use(0, *Ron);
	Ron->use(0, *Jim);

	std::cout << _R << "###################################\n";
	std::cout << _R << "# Taking invalid weapon from pool #\n";
	std::cout << _R << "###################################\n";
	Jim->equip(weapon_pool->TAKE_FROM_POOL("fire"));
	Ron->equip(weapon_pool->TAKE_FROM_POOL("donuts"));

	std::cout << _R << "################\n";
	std::cout << _R << "# Filling pool #\n";
	std::cout << _R << "################\n";
	weapon_pool->ADD_WEAPON_TO_POOL(new Ice());
	weapon_pool->ADD_WEAPON_TO_POOL(new Cure());

	std::cout << _R << "####################\n";
	std::cout << _R << "# Overflowing pool #\n";
	std::cout << _R << "####################\n";
	weapon_pool->ADD_WEAPON_TO_POOL(new Ice());


	std::cout << _R << "#####################\n";
	std::cout << _R << "# Equiping too much #\n";
	std::cout << _R << "#####################\n";
	Jim->equip(weapon_pool->TAKE_FROM_POOL("ice"));
	Jim->equip(weapon_pool->TAKE_FROM_POOL("ice"));
	Jim->equip(weapon_pool->TAKE_FROM_POOL("ice"));
	Jim->equip(weapon_pool->TAKE_FROM_POOL("cure"));

	std::cout << _R << "#####################\n";
	std::cout << _R << "# Unequiping        #\n";
	std::cout << _R << "#####################\n";
	Jim->unequip(4);
	Jim->use(3, *Ron);
	Jim->unequip(3);
	Jim->use(3, *Ron);
	Jim->unequip(2);
	Jim->unequip(1);
	Jim->unequip(0);

	delete Jim;
	delete Ron;
	delete weapon_pool;
	return 0;
}


//$> clang++ -W -Wall -Werror *.cpp
//$> ./a.out | cat -e
//* shoots an ice bolt at bob *$
//* heals bob's wounds *$
