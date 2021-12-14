/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:19:35 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/14 16:55:25 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie {
public:

	static int	getNbAccounts(void);
	static void	displayAccountsInfos(void);

	void                        announce(void);
	void	makeDeposit(int     deposit);
	bool	makeWithdrawal(int  withdrawal);
	int		checkAmount(void)   const;
	void	displayStatus(void) const;
	Zombie *newZombie(std::string name);
	void setName(std::string name);
	Zombie( std::string name);
	~Zombie( void );
private:
	std::string _name;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	//Zombie(void);

};

#endif
