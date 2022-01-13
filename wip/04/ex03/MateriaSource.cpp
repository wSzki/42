/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:22:59 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/13 01:36:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MateriaSource.hpp"

// Default
MateriaSource::MateriaSource (void) : n_materia(0)
{
	std::cout << "[MateriaSource] Default constructor called\n";
	for (int i = 0; i < 4; i++)
		saved_materia[i] = NULL;
}

// Copy
MateriaSource::MateriaSource(MateriaSource const &obj) : n_materia(0)
{
	std::cout << "[MateriaSource] Copy constructor called\n";
	for (int i = 0; i < obj.n_materia; i++)
	{
		this->learnMateria(obj.saved_materia[i]);
		this->n_materia++;
	}
}

// OVERLOADS
MateriaSource &MateriaSource::operator = (MateriaSource const &obj)
{
	std::cout << "[MateriaSource] Assignation operator called" << std::endl;
	this->n_materia = 0;
	for (int i = 0; i < obj.n_materia; i++)
	{
		this->learnMateria(obj.saved_materia[i]);
		this->n_materia++;
	}
	return (*this);
}

// METHODS
void MateriaSource::learnMateria(AMateria *materia)
{
	if (this->n_materia == 4)
		return ;
	this->saved_materia[this->n_materia] = materia;
	this->n_materia++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	(void)type;
	return NULL;

}

// DESTRUCTOR
MateriaSource::~MateriaSource (void)
{
	std::cout << "[MateriaSource] Destructor Called\n";
	for (int i = 0; i < this->n_materia; i++)
		delete this->saved_materia[i];

}
