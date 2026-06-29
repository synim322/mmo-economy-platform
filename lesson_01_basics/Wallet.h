#pragma once

class Wallet
{
private:
	int balance;

	static constexpr int MinBalance = 0;
	static constexpr int MinAmount = 1;
public:
	Wallet(int initialBalance = 0);
	~Wallet();

	int GetBalance() const;
	void Deposit(int amount);
	void Withdraw(int amount);
	bool CanSpend(int amount) const;
	void PrintBalance() const;
};