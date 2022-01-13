/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:03:58 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 01:36:17 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{


	AMateria *obj = new Ice();
	std::cout << obj->getType();

	delete obj;


	// Creating empty array[4]
	IMateriaSource* src = new MateriaSource();

	// Adding materia to array index [0] & [1]
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	//ICharacter* me = new Character("me");
	//AMateria* tmp;
	//tmp = src->createMateria("ice");
	//me->equip(tmp);
	//tmp = src->createMateria("cure");
	//me->equip(tmp);
	//ICharacter* bob = new Character("bob");
	//me->use(0, *bob);
	//me->use(1, *bob);
	//delete bob;
	//delete me;
	//delete src;
	//return 0;
}


//$> clang++ -W -Wall -Werror *.cpp
//$> ./a.out | cat -e
//* shoots an ice bolt at bob *$
//* heals bob's wounds *$
