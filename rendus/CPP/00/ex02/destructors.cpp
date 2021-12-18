/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:11:15 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/16 20:11:35 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>

Account::~Account(void)
{
	_displayTimestamp();
	std::cout     << "index:"  << this->_accountIndex << ";";
	std::cout     << "amount:" << this->_amount       << ";";
	std::cout     << "closed"  << "\n";
	this->_amount =  0;
}
