#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}
int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{   
	std::time_t now = std::time(0);
	std::tm *lt = std::localtime(&now);

	char buffer[20];
	std::strftime(buffer, 20, "%Y%m%d_%H%M%S", lt);

	std::cout << "[" << buffer << "] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

Account::Account(int initial_deposit)
{	
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	_totalAmount +=deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount - deposit   // previous amount
			<< ";deposit:" << deposit
			<< ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;

}
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout 	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}
