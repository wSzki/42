/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:43:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/06 15:10:19 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <cstddef>


int main()
{

	std::cout << _R << "\n# BASIC TESTS ##########################################################################\n";
	std::cout << GREEN << std::endl;

	const Animal* unknown = new Animal();
	const Animal* dog     = new Dog();
	const Animal* cat     = new Cat();

	std::cout << _R << std::endl;
	std::cout << unknown->getType() << " says "; unknown->makeSound();
	std::cout << dog->getType()     << " says "; dog->makeSound();
	std::cout << cat->getType()     << " says "; cat->makeSound();

	std::cout << RED << std::endl;
	delete unknown;
	delete dog;
	delete cat;

	std::cout << _R << "\n# ARRAY TESTS ###########################################################################\n";
	size_t i = 0;
	const Animal* zoo[10];

	std::cout << GREEN << std::endl;
	while (i < 5)
		zoo[i++] = new Dog();
	std::cout << CYAN << std::endl;
	while (i < 10)
		zoo[i++] = new Cat();

	std::cout <<std::endl << _R ;
	i = 0;
	while (i < 10)
	{
		std::cout << zoo[i]->getType() << " wants to "<< zoo[i]->getIdea() << std::endl;
		i++;
	}

	std::cout << RED << std::endl;
	i = 0;
	while (i < 5)
		delete zoo[i++];
	std::cout << std::endl;
	while (i < 10)
		delete zoo[i++];

	std::cout << _R << "\n# DEEP COPY TESTS ########################################################################\n";

	std::cout << YELLOW << "\nCREATING ORIGINAL CAT AND DOG\n################################\n";
	Cat newCat;
	Dog newDog;


	std::cout << "\n";
	std::cout << newCat.getType()<< " wants to :\n" ;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << newCat.getBrain().getIdea(i) << std::endl;
	std::cout << "\n";
	std::cout << newDog.getType()<< " wants to :\n" ;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << newDog.getBrain().getIdea(i) << std::endl;

	std::cout << LIGHT_RED << "\nCREATING COPIES OF CAT AND DOG\n################################\n";
	Cat copyCat = newCat;
	Dog copyDog = newDog;

	std::cout << "\n";
	std::cout << copyCat.getType()<< " wants to :\n" ;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << copyCat.getBrain().getIdea(i) << std::endl;
	std::cout << "\n";
	std::cout << copyDog.getType()<< " wants to :\n" ;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << copyDog.getBrain().getIdea(i) << std::endl;

	std::cout << LIGHT_GRAY << "\nMODIFIYING COPIES OF CAT AND DOG \n################################\n";


	copyCat.setType("Dog");
	copyCat.getBrain().setIdea("Eat pasta", 0);
	copyCat.getBrain().setIdea("Eat pizza", 1);
	copyCat.getBrain().setIdea("Eat bird", 2);
	copyCat.getBrain().setIdea("Eat dog", 3);
	copyCat.getBrain().setIdea("Eat sand", 4);

	copyDog.setType("Cat");
	copyDog.getBrain().setIdea("Build house", 0);
	copyDog.getBrain().setIdea("Cook burger", 1);
	copyDog.getBrain().setIdea("Vote", 2);
	copyDog.getBrain().setIdea("Dance", 3);
	copyDog.getBrain().setIdea("Talk", 4);

	std::cout << "\n";
	std::cout << copyCat.getType()<< " (previously Cat) wants to :\n" ;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << copyCat.getBrain().getIdea(i) << std::endl;
	std::cout << "\n";
	std::cout << copyDog.getType()<< " (previously Dog) wants to :\n" ;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << copyDog.getBrain().getIdea(i) << std::endl;


	std::cout << _R << "\nCHECKING ORIGINAL CAT AND DOG \n################################\n";
	std::cout << "\n";
	std::cout << newCat.getType()<< " wants to :\n" ;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << newCat.getBrain().getIdea(i) << std::endl;
	std::cout << "\n";
	std::cout << newDog.getType()<< " wants to :\n" ;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << newDog.getBrain().getIdea(i) << std::endl;

	//Dog copyDog;
	//Cat copyCat;
	std::cout << _R << "\n";

	std::cout << RED << std::endl;
}
