/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:59:06 by mdahani           #+#    #+#             */
/*   Updated: 2025/09/15 18:35:27 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>
#include <ctime>

// definition of static variables to reserves a place in memory
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit){
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

// Destructor
Account::~Account(){
    _nbAccounts--;
    _totalAmount -= this->_amount;

    _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
}

// Methodes
int Account::getNbAccounts(){
    return _nbAccounts;
}

int Account::getTotalAmount(){
    return _totalAmount;
}

int Account::getNbDeposits(){
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(){
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << ";"
        << std::endl;
}

void Account::makeDeposit(int deposit){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";"
        << "deposits:" << this->_nbDeposits << ";" << "withdrawals:" << this->_nbWithdrawals << ";"
        << "closed" << std::endl;

    this->_amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    this->_nbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << this->_amount << ";" << "withdrawal:";

    if (withdrawal > this->_amount){
        std::cout << "refused" << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;

    std::cout << withdrawal << ";" << "amount:" << this->_amount << ";" << "nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;

    return true;
}


int Account::checkAmount() const {
    return this->_amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";"
        << "deposits:" << this->_nbDeposits << ";" << "withdrawals:" << this->_nbWithdrawals << ";"
        << std::endl;
}

void Account::_displayTimestamp(){
    // get time from 1 jan 1970 on seconds
    std::time_t now = std::time(NULL);
    
    // Pointer to a tm structure containing time parts (year, month, day, hour, minute, second).
    // localtime function is converts to local time according to system settings
    std::tm *time = std::localtime(&now);

    char buffer[20];
    
    // format the date and time like this [19920104_091532]
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", time);

    std::cout << buffer << " ";
}
