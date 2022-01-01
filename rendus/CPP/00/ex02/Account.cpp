/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:57:35 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/16 20:14:52 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"

#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void prepend_zero_if_needed_then_print(int value)
{
	if (value < 10)
		std::cout << 0;
	std::cout << value;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	now;
	struct tm	timestruct;

	now = time(0);
	timestruct = *localtime(&now);
	std::cout << "[";
	prepend_zero_if_needed_then_print(timestruct.tm_year + 1900);
	prepend_zero_if_needed_then_print(timestruct.tm_mon);
	prepend_zero_if_needed_then_print(timestruct.tm_mday);
	std::cout << "_";
	prepend_zero_if_needed_then_print(timestruct.tm_hour);
	prepend_zero_if_needed_then_print(timestruct.tm_min);
	prepend_zero_if_needed_then_print(timestruct.tm_sec);
	std::cout << "] ";
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:"    << Account::getNbAccounts()    << ";";
	std::cout << "total:"       << Account::getTotalAmount()   << ";";
	std::cout << "deposits:"    << Account::getNbDeposits()    << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits += 1;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:"       << this->_accountIndex << ";";
	std::cout << "p_amount:"    << p_amount            << ";";
	std::cout << "deposit:"     << deposit             << ";";
	std::cout << "amount:"      << this->_amount       << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits   << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{

	_displayTimestamp();

	std::cout << "index:"       << this->_accountIndex << ";";
	std::cout << "p_amount:"    << this->_amount       << ";";
	if (this->_amount - withdrawal < 1)
	{
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;

	std::cout << "withdrawal:"     << withdrawal           << ";";
	std::cout << "amount:"         << this->_amount        << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return (true);
}


void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:"       << this->_accountIndex  << ";";
	std::cout << "amount:"      << this->_amount        << ";";
	std::cout << "deposits:"    << this->_nbDeposits    << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}


