/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:22:59 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/20 23:39:17 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "./MateriaSource.hpp"

// Default
MateriaSource::MateriaSource (void)
{
	std::cout << GREEN << "[MateriaSource] Default constructor called\n";
	for (int i = 0; i < 4; i++)
		saved_materia[i] = NULL;
}

// Copy
MateriaSource::MateriaSource(MateriaSource const &obj)
{
	std::cout << GREEN << "[MateriaSource] Copy constructor called\n";
	if (this == &obj)
		return ;
	for (int i = 0; obj.saved_materia[i] != NULL; i++)
		this->learnMateria(obj.saved_materia[i]);
}

// OVERLOADS
MateriaSource &MateriaSource::operator = (MateriaSource const &obj)
{
	std::cout << GREEN << "[MateriaSource] Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	for (int i = 0; obj.saved_materia[i] != NULL; i++)
		this->learnMateria(obj.saved_materia[i]);
	return (*this);
}

// METHODS
void MateriaSource::learnMateria(AMateria *materia)
{
	int i = 0;

	while (saved_materia[i])
		i++;
	if (i == 4)
	{
		std::cout << RED << "[ERROR] " << _R << "Materia source is full\n";
		delete materia;
		return ;
	}
	this->saved_materia[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; this->saved_materia[i] != NULL; i++)
		if (this->saved_materia[i]->getType() == type)
			return this->saved_materia[i]->clone();
	std::cout << RED << "[ERROR] " << _R << "Unavailable Materia\n";
	return (NULL);
}

// DESTRUCTOR
MateriaSource::~MateriaSource (void)
{
	std::cout << RED << "[MateriaSource] Destructor Called\n";
	for (int i = 0; this->saved_materia[i] != NULL; i++)
		delete this->saved_materia[i];

}
