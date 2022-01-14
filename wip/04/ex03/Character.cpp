/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:03:00 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 21:36:25 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "colors.hpp"

// Default
Character::Character (void) : name("null")
{
	std::cout << GREEN "[Character] Default constructor called\n" << _R;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character (std::string name) : name(name)
{
	std::cout << GREEN "[Character] Constructor called\n" << _R;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

// Copy
Character::Character(Character const &obj)
{
	std::cout << GREEN "[Character] Copy constructor called\n" << _R;
	this->name = obj.name;
	for (int i = 0; i < 4; i++)
		if (obj.inventory[i] != NULL)
			this->equip(obj.inventory[i]);
}

// OVERLOADS
Character &Character::operator = (Character const &obj)
{
	std::cout << GREEN "[Character] Assignation operator called" << _R << std::endl;
	this->name = obj.name;
	for (int i = 0; i < 4; i++)
		if (obj.inventory[i] != NULL)
			this->equip(obj.inventory[i]);
	return (*this);
}

// METHODS
std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (m == NULL)
		return ;
	while(this->inventory[i] != NULL)
		i++;
	this->inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
	// TODO
}

// DESTRUCTOR
Character::~Character (void)
{
	std::cout << RED << "[Character] Destructor Called\n" <<  _R;
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
}
