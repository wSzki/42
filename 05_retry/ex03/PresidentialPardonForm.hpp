/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:18:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/02 02:25:20 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRES_H__
#define __PRES_H__
#include <iostream>
#include <cctype>
#include "Form.hpp"

class PresidentialPardonForm : virtual public Form
{
	public:

	PresidentialPardonForm  (void);
	PresidentialPardonForm  (std::string target);
	virtual ~PresidentialPardonForm (void);
	PresidentialPardonForm  (PresidentialPardonForm const &obj);

	PresidentialPardonForm &operator = (PresidentialPardonForm  const &obj);

	virtual void execute(Bureaucrat const & executor) const;

	private:
	std::string const target;

	protected:

};

#endif
