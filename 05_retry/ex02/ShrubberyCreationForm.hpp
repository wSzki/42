/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:18:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/02 02:22:44 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUB_H__
#define __SHRUB_H__
#include <iostream>
#include <cctype>
#include "Form.hpp"

class ShrubberyCreationForm : virtual public Form
{
	public:

	ShrubberyCreationForm  (void);
	ShrubberyCreationForm  (std::string target);
	virtual ~ShrubberyCreationForm (void);
	ShrubberyCreationForm  (ShrubberyCreationForm const &obj);

	ShrubberyCreationForm &operator = (ShrubberyCreationForm  const &obj);

	virtual void execute(Bureaucrat const & executor) const;

	private:
	std::string const target;

	protected:

};

#endif
