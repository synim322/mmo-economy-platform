#include "Agent.h"
#include "Wallet.h"
#include <iostream>

Agent::Agent(int agentId, const std::string& agentName, int initialBalance) : id{ agentId }, nameAgent{ agentName }, wallet{ initialBalance }
{
	if (agentName.empty())
	{
		nameAgent = "DefaultAgent";
	}

	if (agentId < MinId)
	{
		id = MinId;
	}

	std::cout << "Agent created" << "\n";
}

Agent::~Agent()
{
	std::cout << "Agent destroyed" << "\n";
}

int Agent::GetId() const
{
	return id;
}

const std::string& Agent::GetName() const
{
	return nameAgent;
}

int Agent::GetWalletBalance() const
{
	return wallet.GetBalance();
}

void Agent::Deposit(int amount)
{
	wallet.Deposit(amount);
}

void Agent::Withdraw(int amount)
{
	wallet.Withdraw(amount);
}

void Agent::PrintInfo() const
{
	std::cout << "Agent ID: " << id << "\n";
	std::cout << "Agent Name: " << nameAgent << "\n";
	wallet.PrintBalance();
}
