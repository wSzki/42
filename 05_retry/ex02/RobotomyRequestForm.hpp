/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:18:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/02 02:22:38 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTO_H__
#define __ROBOTO_H__
#include <iostream>
#include <cctype>
#include "Form.hpp"

class RobotomyRequestForm : virtual public Form
{
	public:

	RobotomyRequestForm  (void);
	RobotomyRequestForm  (std::string target);
	virtual ~RobotomyRequestForm (void);
	RobotomyRequestForm  (RobotomyRequestForm const &obj);

	RobotomyRequestForm &operator = (RobotomyRequestForm  const &obj);

	virtual void execute(Bureaucrat const & executor) const;

	private:
	std::string const target;

	protected:

};

#endif
