/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:02:06 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 16:17:20 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	++_nbAccounts;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount"
			<< this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount:"
			<< this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount;

	p_amount = this->_amount;
	this->_amount += deposit;
	++this->_nbDeposits;
	++_totalNbDeposits;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
		<< ";deposit:" << deposit << ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->_amount - withdrawal < 0) {
		std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount << ";withdrawal:refused"
			<< std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount << ";nbWithdrawals:" << this->_nbWithdrawals
		<< std::endl;
    return true;
}

void Account::_displayTimestamp()
{
	time_t nowTime;
	tm*    localTime;

	time(&nowTime);
	localTime = std::localtime(&nowTime);
	std::cout << std::setfill('0') << "[" << (localTime->tm_year + 1900);
	std::cout << std::setw(2) << localTime->tm_mon;
	std::cout << std::setw(2) << localTime->tm_mday << "_";
	std::cout << std::setw(2) << localTime->tm_hour;
	std::cout << std::setw(2) << localTime->tm_min;
	std::cout << std::setw(2) << localTime->tm_sec << "] ";
}

