#include "Wallet.h"
#include <iostream>

Wallet::Wallet(int initialBalance) : balance{ initialBalance }
{
	if (initialBalance < MinBalance)
	{
		balance = MinBalance;
	}

	std::cout << "Wallet created: " << "\n";
}

Wallet::~Wallet()
{
	std::cout << "Wallet destroyed" << "\n";
}

int Wallet::GetBalance() const
{
	return balance;
}

void Wallet::Deposit(int amount)
{
	if (amount < MinAmount)
	{
		return;
	}
	else
	{
		balance += amount;
	}
}

void Wallet::Withdraw(int amount)
{
	if (amount < MinAmount || !CanSpend(amount))
	{
		return;
	}
	else
	{
		balance -= amount;
	}

	return;
}

bool Wallet::CanSpend(int amount) const
{
	if (amount < MinAmount || balance - amount < MinBalance)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Wallet::PrintBalance() const
{
	std::cout << "Wallet Balance: " << balance << '\n';
}
