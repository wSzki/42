/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:57:35 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/19 16:41:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit)
{
	(void)initial_deposit;
}

Account::Account( void)
{
}

Account::~Account( void)
{
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);

}

void Account::displayAccountsInfos( void )
{

}

////////////////////////////////////////////////////////////////

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_amount -= withdrawal;
	this->_nbDeposits += 1;
	return (1);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{


}



int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;


	Account Account;

	return (0);
}
