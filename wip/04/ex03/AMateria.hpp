/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:04:41 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/14 16:49:10 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_H__
# define __AMATERIA_H__
# include <iostream>
# include <cctype>

//# include "MateriaSource.hpp"
//# include "IMateriaSource.hpp"
//#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	public:

		AMateria  (void);
		AMateria  (AMateria    const &obj);
		AMateria  (std::string const &type);
		virtual ~AMateria (void);

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;

		AMateria &operator = (AMateria const &obj);

	private:

	protected:
		std::string type;

};

#endif
