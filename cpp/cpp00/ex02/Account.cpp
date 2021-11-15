/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:57:35 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/15 17:36:00 by wszurkow         ###   ########.fr       */
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


void	makeDeposit( int deposit )
{

}
bool	Account::makeWithdrawal( int withdrawal )
{
	this->_amount = 0;


}
int		Account::checkAmount( void );
void	Account::displayStatus( void );

