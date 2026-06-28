#pragma once
#include <string>
#include "Wallet.h"

class Agent
{
private:
	int id;
	std::string nameAgent;
	Wallet wallet;

	static constexpr int MinId = 1;
	static constexpr const char* DefaultName = "DefaultAgent";
public:
	Agent(int agentId, const std::string& agentName, int initialBalance);
	~Agent();

	int GetId() const;
	const std::string& GetName() const;
	int GetWalletBalance() const;

	void Deposit(int amount);
	bool Withdraw(int amount);
	void PrintInfo() const;
};