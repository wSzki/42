/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:43:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/04 02:31:44 by wszurkow         ###   ########.fr       */
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

	std::cout << _R << "\n# BASIC TESTS";
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

	std::cout << _R << "\n# ARRAY TESTS";
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

}
