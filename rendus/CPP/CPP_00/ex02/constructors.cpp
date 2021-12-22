/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors_destructors.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:10:39 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/16 20:11:09 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"

#include <iostream>

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	this->_accountIndex = Account::_nbAccounts - 1;
	std::cout << "index:"  << this->_accountIndex << ";";
	std::cout << "amount:" << initial_deposit     << ";";
	std::cout << "created" << "\n";
}

Account::Account (void)
{
	_displayTimestamp();
	this->_amount = 0;
	Account::_nbAccounts++;
	this->_accountIndex = Account::_nbAccounts - 1;
	std::cout << "index:"  << this->_accountIndex << ";";
	std::cout << "amount:" << 0                   << ";";
	std::cout << "created" << "\n";
}


