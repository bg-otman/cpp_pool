#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

std::string format_time(int time)
{
	std::stringstream sstr;
	sstr << time;
	if (time >= 10)
		return sstr.str();
	return "0" + sstr.str();
}

void	Account::_displayTimestamp( void )
{
	time_t	curr_time = time(NULL);
	tm		*tm_local = localtime(&curr_time);

	std::cout 	<< "[" << tm_local->tm_year + 1900
				<< format_time(tm_local->tm_mon + 1)
				<< format_time(tm_local->tm_mday)
				<< "_"
				<< format_time(tm_local->tm_hour)
				<< format_time(tm_local->tm_min)
				<< format_time(tm_local->tm_sec)
				<< "] ";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
			<< "total:" << _totalAmount << ";"
			<< "deposits:" << _totalNbDeposits << ";"
			<< "withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit)
{
	if (_nbDeposits >= 0)
	{
		_displayTimestamp();
		std::cout 	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount + deposit << ";"
				<< "nb_deposits:" << _nbDeposits + 1 << "\n";
	}
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (_amount - withdrawal >= 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout 	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount - withdrawal << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << "\n";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return true;
	}
	std::cout 	<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:refused" << "\n";
	return false;
}

int		Account::checkAmount() const
{
	return _amount;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << "\n";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = 0;
	_nbWithdrawals = 0;
	_nbDeposits = -1;
	_totalNbDeposits--;
	makeDeposit(initial_deposit);
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";closed\n";
}
