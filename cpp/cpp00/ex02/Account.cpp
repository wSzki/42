/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:57:35 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/16 15:57:52 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
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

//void	displayStatus( void );
//{


//}
