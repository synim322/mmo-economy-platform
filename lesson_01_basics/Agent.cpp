#include "Agent.h"
#include <iostream>

Agent::Agent(int agentId, const std::string& agentName, int initialBalance) : id{ agentId }, nameAgent{ agentName }, wallet{ initialBalance }
{
	if (agentName.empty())
	{
		nameAgent = DefaultName;
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

bool Agent::Withdraw(int amount)
{
	return wallet.Withdraw(amount);
}

void Agent::PrintInfo() const
{
	std::cout << "Agent ID: " << id << "\n";
	std::cout << "Agent Name: " << nameAgent << "\n";
	wallet.PrintBalance();
}
