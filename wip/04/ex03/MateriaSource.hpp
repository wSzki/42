/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:14:49 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/14 16:25:49 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOUCRE_H__
#define __MATERIASOUCRE_H__
#include <iostream>
#include <cctype>

#include "IMateriaSource.hpp"

class AMateria;
class IMateriaSource;
class MateriaSource : virtual public IMateriaSource
{
	public:

		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource (MateriaSource const &obj);

		MateriaSource &operator = (MateriaSource const &obj);

		// FROM INTERFACE IMATERIASROUCE
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria *saved_materia[4];

	protected:

};

#endif
