/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:43:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/21 17:08:50 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <cstddef>



void test_1(void)
{
	std::cout << _R << "\n# BASIC TESTS ##########################################################################\n";
	std::cout << GREEN << std::endl;
	// ######################################### //
	// UNCOMMENT TO SHOW ERRORS
	//const Animal* unknown = new Animal();
	//Animal beast;
	// ######################################### //
	const Animal* dog     = new Dog();
	const Animal* cat     = new Cat();

	std::cout << _R << std::endl;
	std::cout << dog->getType()     << " says "; dog->makeSound();
	std::cout << cat->getType()     << " says "; cat->makeSound();

	std::cout << RED << std::endl;
	delete dog;
	delete cat;
}

void test_2(void)
{
	std::cout << _R << "\n# ARRAY TESTS ###########################################################################\n";
	size_t i = 0;
	const Animal* animal[10];

	// Creating dogs
	std::cout << GREEN << std::endl;
	while (i < 5)
		animal[i++] = new Dog();

	// Creating cats
	std::cout << CYAN << std::endl;
	while (i < 10)
		animal[i++] = new Cat();

	std::cout <<std::endl << _R ;

	i = 0;
	while (i < 10)
	{
		std::cout << animal[i]->getType() << " says " ;
		animal[i]->makeSound();
		i++;
	}

	std::cout << RED << std::endl;
	i = 0;
	while (i < 5)
		delete animal[i++];
	std::cout << std::endl;
	while (i < 10)
		delete animal[i++];
}

void test_3(void)
{
	std::cout << _R << "\n# OTHER DEEP COPY TESTS ########################################################################\n";

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

	std::cout << "\n########################################################\n";
	std::cout << "Address of cat's brain : " << &(newCat.getBrain()) << "\n";
	std::cout << "Address of cat's brain copy : " << &(copyCat.getBrain()) << "\n";
	std::cout << "Address of dogs's brain : " << &(newDog.getBrain()) << "\n";
	std::cout << "Address of dogs's brain copy : " << &(copyDog.getBrain()) << "\n";
	std::cout << "########################################################\n";

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

void test_4(void)
{
	std::cout << _R << "\n# CONSTRUCTOR TESTS ########################################################################\n";
	std::cout << GREEN;
	Cat b;
	Cat a = b;
	Cat c(b);
	Brain *brain;
	brain = new Brain();
	Brain bbb;
	Brain Drain(bbb);
	Animal *dog = new Dog();
	Animal *cog = dog;
	Dog *doggo(new Dog());
	Cat catto = a;
	Cat *catta = new Cat();
	(void)cog;

	std::cout << RED;
	delete brain;
	delete dog;
	delete doggo;
	delete catta;
}

int main()
{
	test_1();
	test_2();
	test_3();
	test_4();
}
