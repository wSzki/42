/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:43:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/03 19:37:48 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << GREEN;
	std::cout << "##### Creating animals" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << YELLOW;
	std::cout << "##### Types of created animals" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "##### Animal sounds" << std::endl;
	std::cout << _R;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	std::cout <<  GREEN;
	std::cout << "##### Creating wrong animals" << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	std::cout << YELLOW;
	std::cout << "##### Types of created wrong animals" << std::endl;
	std::cout << wrong->getType() << std::endl;
	std::cout << wcat->getType() << std::endl;
	std::cout << _R;
	std::cout << "##### Wrong animal sounds" << std::endl;
	wrong->makeSound();
	wcat->makeSound();

	std::cout << RED;
	std::cout << "##### Freeing all objects\n";
	delete meta;
	delete i;
	delete j;
	delete wrong;
	delete wcat;
	std::cout << _R;
}
