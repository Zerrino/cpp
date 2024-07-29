/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 03:48:05 by alexafer          #+#    #+#             */
/*   Updated: 2024/05/13 08:59:33 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::string	tm;
	std::time_t	curr_time;
	curr_time = std::time(NULL);
	
	std::cout << std::setfill('0')
	<< "[" << std::localtime(&curr_time)->tm_year + 1900
	<< std::setw(2) << std::localtime(&curr_time)->tm_mon + 1
	<< std::setw(2) << std::localtime(&curr_time)->tm_mday
	<< "_"
	<< std::setw(2) << std::localtime(&curr_time)->tm_hour
	<< std::setw(2) << std::localtime(&curr_time)->tm_min
	<< std::setw(2) << std::localtime(&curr_time)->tm_sec << "] " << std::flush;
}

Account::Account(int initial_deposit)
{
	std::cout << initial_deposit << std::endl;
	_displayTimestamp();
}

Account::~Account()
{}
